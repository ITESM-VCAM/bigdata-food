import pyspark.sql as pssql
# from pyspark.sql import SparkSession
# from pyspark.sql.types import StructType, StructField, IntegerType, StringType

# load spark session
spark = pssql.SparkSession.builder.appName("food").getOrCreate()

# Filter and count high calorie foods
dataset = spark.read.csv("dataset/dataset.csv", header=True, inferSchema=True)
high_calorie_foods = dataset.filter(dataset.kilocalories > 100)
entry_count = high_calorie_foods.count()
print(f"Number of entries with over 100 kilocalories: {entry_count}")

# save results to file
high_calorie_foods.write.json("results/high_calorie_foods_json")

# stop spark session
spark.stop()
