// Databricks notebook source
val dfs = sqlContext.read.json("dbfs:/FileStore/first.json")
dfs.show
dfs.printSchema()
dfs.select("Age").show
dfs.select("Name").show
dfs.groupBy("Age").count().show

// COMMAND ----------

import org.apache.spark.sql.SparkSession
val spark = SparkSession.builder().appName("SparkExample").master("local").getOrCreate
import org.apache.spark.sql.SparkSession
// comment
// initialization of spark appName
val state = Map(("NY", "New York"), ("CA", "Califonia"), ("FL", "Florida"))
val countries = Map(("USA", "United States of America"), ("IN", "India"))
val broadcastState = spark.sparkContext.broadcast(state)
val broadcastCountries = spark.sparkContext.broadcast(countries)

val data = Seq(("Mit", "Patel", "IN", "CA"), 
               ("Kush", "Chavala", "USA", "CA"),
               ("Mire", "Patel", "IN", "NY"),
               ("Parth", "Patel", "USA", "FL"))

val rdd = sc.parallelize(data)
val rdd2 = rdd.map(f => {
  val country = f._3
  val state = f._4
  val fullCountry = broadcastCountries.value.get(country).get
  val fullState = broadcastState.value.get(state).get
  (f._1, f._2, fullCountry, fullState)
})


val columns = Seq("Name", "LastName", "Country", "State")
import spark.sqlContext.implicits._


val df = data.toDF(columns:_*)
val df2 = df.map(row => {
  val country = row.getString(2)
  val state = row.getString(3)
  val fullState = broadcastState.value.get(state).get
  val fullCountry = broadcastCountries.value.get(country).get
  (row.getString(0), row.getString(1), fullCountry, fullState)
}).toDF(columns:_*)

// COMMAND ----------

println(rdd2.collect().mkString("\n"))
df2.show

val longAcc = spark.sparkContext.longAccumulator("SUM")
val rdd = spark.sparkContext.parallelize(Array(1, 2, 3, 4, 5, 6, 7))
rdd.collect
rdd.foreach(x => longAcc.add(x))
longAcc.value
