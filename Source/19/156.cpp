#include <iostream>
#include <vector>
#include <random>

void random_vector(std::vector<int> &vec) {
    std::random_device seed_generator;
    std::mt19937 random_generator(seed_generator());
    std::uniform_int_distribution<int> random_distribution(-10,10);

    for (auto& val : vec) {
        val = random_distribution(random_generator);
    }
}
