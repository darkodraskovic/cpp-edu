#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printVector(const vector<T> vec) {
    for (typename vector<T>::const_iterator it = vec.begin(); it < vec.end(); it++) {
        cout << *it << ", ";
    }
    cout << "\n";
}

template <typename T>
void swap(T& a, T& b) {
    T tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}

int main(int argc, char *argv[]) {
    vector<int> vec1{0, 1, 2, 3, 4};
    vector<int> vec2{5, 6, 7, 8, 9};

    printVector(vec1);
    printVector(vec2);

    swap(vec1, vec2);
    
    printVector(vec1);
    printVector(vec2);
    
    return 0;
}

