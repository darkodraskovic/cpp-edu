#include <iostream>

template <typename T> T concat(T first) { return first; }

template <typename T, typename... Args>
T concat(T first, Args... args) {
    return first + concat(args...);
}

// since C++17
template <typename T, typename... Args>
T concat(Args... args) {
    return (args + ...);
}

int main() {
    std::string s1 = "Ha";
    std::string s2 = "ll";
    std::string s3 = "o";

    std::cout << concat(s1, s2, s3) << "\n";
    std::cout << concat<std::string>(s1, s2, s3) << "\n"; // C++17

    std::cout << concat(1, 2, 3, 4) << "\n";
    std::cout << concat<int>(1, 2, 3, 4) << "\n"; // C++17
    
    return 0;
}
