#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

#include "156.cpp"

void f1() {
    std::vector<int> vector_a(10,0);
    random_vector(vector_a);
    for (auto& val : vector_a) std::cout << val << "\n";
    std::cout << "\n\n" << "\n";

    std::vector<int> vector_b(10,0);
    random_vector(vector_b);
    std::vector<int> vector_c(10,0);
    random_vector(vector_c);
    std::vector<int> vector_d(10,0);
    // random_vector(vector_d);

    for (auto& val : vector_b) std::cout << val << "\n";
    int sum_vector_b = std::reduce(vector_b.begin(), vector_b.end());
    std::cout << "sum_vector_b = " << sum_vector_b << "\n";
    int sum_vector_b_plus_2 = std::reduce(vector_b.begin(), vector_b.end(), 2);
    std::cout << "sum_vector_b = " << sum_vector_b_plus_2 << "\n";
    std::cout << "\n\n" << "\n";
    
    for (auto& val : vector_b) std::cout << val << "\n";
    int sum_vector_c = std::accumulate(vector_c.begin(), vector_c.end(), 0);
    std::cout << "sum_vector_c = " << sum_vector_c << "\n";
    int mult_vector_c = std::accumulate(vector_c.begin(), vector_c.end(), 1, std::multiplies<int>());
    std::cout << "mult_vector_c = " << mult_vector_c << "\n";
    std::cout << "\n\n" << "\n";
}

bool replace_even(int i) {
    if (i % 2 == 0) return true;
    return false;
}

void f2() {
    std::vector<int> vector_a = {2, 4, 5, 6, 7, 5, 1};
    
    for(const int& val : vector_a) std::cout << val << ", ";
    std::cout << std::endl;

    std::replace(vector_a.begin(), vector_a.end(), 5, 0);

    for(const int& val : vector_a) std::cout << val << ", ";
    std::cout << std::endl;
}

void f3() {
    std::vector<int> vector_a = {2, 4, 5, 6, 7, 5, 1};
    
    for(const int& val : vector_a) std::cout << val << ", ";
    std::cout << std::endl;

    std::replace_if(vector_a.begin(), vector_a.end(), replace_even, 0);

    for(const int& val : vector_a) std::cout << val << ", ";
    std::cout << std::endl;
}

int main() {

    f3();
    
    return 0;
}
