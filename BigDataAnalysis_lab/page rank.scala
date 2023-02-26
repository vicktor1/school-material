// Databricks notebook source
import org.apache.spark.HashPartitioner

var links = sc.parallelize(List(("MapR", List("Baidu", "Blogger")), ("Baidu", List("MapR")), ("Blogger", List("Google", "Baidu")), ("Google", List("MapR")))).partitionBy(new HashPartitioner(4)).persist()
val ranks = links.mapValues(v => 1.0)
ranks.collect

// COMMAND ----------

val contributions = links.join(ranks).flatMap {case (url, (links, ranks)) => links.map( dest => (dest, ranks  / links.size))}
contributions.collect



// COMMAND ----------


// url_1 url_4
// url_2 url_1
val lines = spark.read.textFile("dbfs:/FileStore/url_text.txt")
val iters = 20 
val links = lines.map{ s =>
  val parts = s.split("\\s+")
  (parts(0), parts(1))
}.distinct().groupByKey().cache()

// COMMAND ----------

var ranks = contributions.reduceByKey((x, y) => x + y).mapValues(v => 0.15 + 0.85 * v)
// alpha / N + (1 - alpha) sigma(rank / N)
ranks.collect

// COMMAND ----------

val iters = 20
for (i <- 1 to iters) {
  val contribs = links.join(ranks).values.flatMap { case (urls, rank) => 
    val size = urls.size
    urls.map(url => (url, rank / size))
  }
  ranks = contribs.reduceByKey(_ + _).mapValues(0.15 + 0.85 * _)
}

// COMMAND ----------

val output = ranks.collect()
val r = ranks.toDF("URL", "PageRank")
output.foreach(tup => println(tup._1 + "has rank: " + tup._2))
println("=======================")
r.show





// COMMAND ----------

r.createOrReplaceTempView("Table")


// COMMAND ----------

val r1 = sqlContext.sql("select PageRank from Table where PageRank > 1")
r1.show

// COMMAND ----------


