// Databricks notebook source
val lines = sc.textFile("dbfs:/FileStore/data.txt")

val lineLengths = lines.map(s => s.length)
lineLengths.collect()
totalLength = lineLengths.reduce((a, b) => a + b)

val data2 = sc.parallelize(List(("B", 5), ("D", 2), ("E", 3)))

val cgf = data1.cogroup(data2)



// COMMAND ----------


val rdd:RDD[String] = sc.textFile("dbfs:/FileStore/data.txt")

println("RDD Partition Count :" + rdd.getNumPartitions)

val rdd2 = rdd.flatMap(f => f.split(" ")).map( m => (m, 1))

// ReduceBy tranformation
val rdd5 = rdd2.reduceByKey(_ + _)
println("RDD Partition Count : " + rdd5.getNumPartitions)

rdd5.collect


// COMMAND ----------

import spark.implicits._

val simpleData = Seq(("James", "Sales", "NY", 90000, 34, 10000),
                    ("Michael", "Sales", "NY", 86000, 56, 24000),
                    ("Scott", "Finance", "NY", 83000, 53, 15000),
                    ("Jen", "Finance", "NY", 79000, 53, 15000),
                     ("Jeff", "Marketing", "CA", 80000, 25, 18000),
                     ("Kumar", "Marketing", "NY", 91000, 50, 21000))

val df = simpleData.toDF("employee_name", "department", "state", "salary", "age", "bonus")
val df2 = df.groupBy("state").count()
println(df2.rdd.getNumPartitions)

// COMMAND ----------



// COMMAND ----------

def isPrime(i :Int) : Boolean = {
    if (i <= 1)
        false
    else if (i == 2)
        true
    else
        !(2 to (i-1)).exists(x => i % x == 0)
}

var data = 0
for( w <- 0 to 1000)
if (isPrime(w))
  data += w
println(data)

// COMMAND ----------

import scala.util.Random
//val myAppSeed = 91234
val newRDD = myRDD.mapPartitionsWithIndex { (indx, iter) =>
   val rand = new scala.util.Random(indx+myAppSeed)
   iter.map(x => (x, Array.fill(10)(rand.nextDouble)))
}


// COMMAND ----------

val lines = sc.textFile("dbfs:/FileStore/data.txt")

val lineLengths = lines.map(s => s.length)
lineLengths.collect()
totalLength = lineLengths.reduce((a, b) => a + b)

val data2 = sc.parallelize(List(("B", 5), ("D", 2), ("E", 3)))

val cgf = data1.cogroup(data2)


// COMMAND ----------


val rdd:RDD[String] = sc.textFile("dbfs:/FileStore/data.txt")

println("RDD Partition Count :" + rdd.getNumPartitions)

val rdd2 = rdd.flatMap(f => f.split(" ")).map( m => (m, 1))

// ReduceBy tranformation
val rdd5 = rdd2.reduceByKey(_ + _)
println("RDD Partition Count : " + rdd5.getNumPartitions)

rdd5.collect

