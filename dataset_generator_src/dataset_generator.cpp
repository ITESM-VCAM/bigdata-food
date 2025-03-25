#include <fstream>
#include <map>
#include <random>
#include <string>

#define MAX_ENTRIES 999999

void load_maps(std::map<int, std::string> &food_map, std::map<int, int> &kilocalories_map)
{
    // The food is in 100 gram portions
    // Using the listed energy in Atwater General Factors
    // Table Salt       https://fdc.nal.usda.gov/food-details/746775/nutrients
    // Fuji Apple       https://fdc.nal.usda.gov/food-details/1750340/nutrients
    // Ataulfo Mango    https://fdc.nal.usda.gov/food-details/2710834/nutrients
    // Russet Potato    https://fdc.nal.usda.gov/food-details/2346401/nutrients
    // Chicken Breast   https://fdc.nal.usda.gov/food-details/2646170/nutrients
    // Raw Garlic       https://fdc.nal.usda.gov/food-details/1104647/nutrients
    // Whole Egg        https://fdc.nal.usda.gov/food-details/748967/nutrients
    // Ground Beef      https://fdc.nal.usda.gov/food-details/2514744/nutrients
    // White Bread      https://fdc.nal.usda.gov/food-details/325871/nutrients
    // Oaxaca Cheese    https://fdc.nal.usda.gov/food-details/2647441/nutrients

    // food names
    food_map.insert({0, "Table Salt"});
    food_map.insert({1, "Fuji Apple"});
    food_map.insert({2, "Ataulfo Mango"});
    food_map.insert({3, "Russet Potato"});
    food_map.insert({4, "Chicken Breast"});
    food_map.insert({5, "Raw Garlic"});
    food_map.insert({6, "Whole Egg"});
    food_map.insert({7, "Ground Beef"});
    food_map.insert({8, "White Bread"});
    food_map.insert({9, "Oaxaca Cheese"});

    // food energy
    kilocalories_map.insert({0, 0});
    kilocalories_map.insert({1, 65});
    kilocalories_map.insert({2, 78});
    kilocalories_map.insert({3, 83});
    kilocalories_map.insert({4, 106});
    kilocalories_map.insert({5, 143});
    kilocalories_map.insert({6, 143});
    kilocalories_map.insert({7, 243});
    kilocalories_map.insert({8, 267});
    kilocalories_map.insert({9, 297});
}

int main()
{
    // load maps of food items
    std::map<int, std::string> food;
    std::map<int, int> kilocalories;
    load_maps(food, kilocalories);

    // load objects for random number generation
    std::random_device generator;
    std::uniform_int_distribution<int> distribution(0, 9);

    // load objects for file output task
    std::ofstream csv_file("dataset.csv");
    std::string data_line;
    int dice_roll;

    // initial header
    csv_file << "key,food,kilocalories" << '\n';

    // generate entries
    for (int i = 0; i < MAX_ENTRIES; i++)
    {
        dice_roll = distribution(generator);

        data_line = std::to_string(i + 1) + ',';
        data_line += food.at(dice_roll) + ',';
        data_line += std::to_string(kilocalories.at(dice_roll));

        csv_file << data_line << '\n';
    }
}
