import pyspark.sql as pssql
import json

# load spark session
spark = pssql.SparkSession.builder.appName("food").getOrCreate()

# Filter and count high calorie foods
dataset = spark.read.csv("dataset/dataset.csv", header=True, inferSchema=True)
high_calorie_foods = dataset.filter(dataset.kilocalories > 100)
entry_count = high_calorie_foods.count()
print(f"Number of entries with over 100 kilocalories: {entry_count}")

# save results to file
json_data = high_calorie_foods.toJSON().collect()
high_calorie_foods.write.mode("overwrite").json("results")
with open('results/data.json', 'w') as file:
    json.dump(json_data, file)

# stop spark session
spark.stop()
