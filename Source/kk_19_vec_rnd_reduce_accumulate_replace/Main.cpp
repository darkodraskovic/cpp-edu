#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

void random_vector(std::vector<int>& vec) {
  std::random_device seed_generator;
  std::mt19937 random_generator(seed_generator());
  std::uniform_int_distribution<int> random_distribution(-10, 10);

  for (auto& val : vec) {
    val = random_distribution(random_generator);
  }
}

void random_reduce_accumulate() {
  std::vector<int> vector_a(10, 0);
  random_vector(vector_a);
  for (auto& val : vector_a) std::cout << val << std::endl;

  std::vector<int> vector_b(10, 0);
  random_vector(vector_b);
  std::vector<int> vector_c(10, 0);
  random_vector(vector_c);

  for (auto& val : vector_b) std::cout << val << "\n";
  int sum_vector_b = std::reduce(vector_b.begin(), vector_b.end());
  std::cout << "sum_vector_b = " << sum_vector_b << "\n";
  int sum_vector_b_plus_2 = std::reduce(vector_b.begin(), vector_b.end(), 2);
  std::cout << "sum_vector_b = " << sum_vector_b_plus_2 << std::endl;

  for (auto& val : vector_b) std::cout << val << "\n";
  int sum_vector_c = std::accumulate(vector_c.begin(), vector_c.end(), 0);
  std::cout << "sum_vector_c = " << sum_vector_c << "\n";
  int mult_vector_c = std::accumulate(vector_c.begin(), vector_c.end(), 1, std::multiplies<int>());
  std::cout << "mult_vector_c = " << mult_vector_c << std::endl;
}

void replace() {
  std::vector<int> vector_a = {2, 4, 5, 6, 7, 5, 1};

  for (const int& val : vector_a) std::cout << val << ", ";
  std::cout << std::endl;

  std::replace(vector_a.begin(), vector_a.end(), 5, 0);

  for (const int& val : vector_a) std::cout << val << ", ";
  std::cout << std::endl;
}

bool replace_even(int i) {
  if (i % 2 == 0) return true;
  return false;
}

void replace_if() {
  std::vector<int> vector_a = {2, 4, 5, 6, 7, 5, 1};

  for (const int& val : vector_a) std::cout << val << ", ";
  std::cout << std::endl;

  std::replace_if(vector_a.begin(), vector_a.end(), replace_even, 0);

  for (const int& val : vector_a) std::cout << val << ", ";
  std::cout << std::endl;
}

int main() {
  random_reduce_accumulate();
  replace();
  replace_if();

  return 0;
}
