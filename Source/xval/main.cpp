#include <iostream>
#include <ostream>
#include <utility>

struct T {
    int _v1;
    int _v2;
    int _v3;

    friend std::ostream& operator<<(std::ostream& os, const T& p) {
        return os << "[ " << p._v1 << " | " << p._v2 << " | " << p._v3 << " ]";
    }
};

struct S
{
    T* _t;

    S() {
        std::cout << "default ctor" << std::endl;
        _t = new T{1,2,3};
    }

    S(const T& t) {
        std::cout << "init instance ctor" << "\n";

        _t = new T{t}; // implicit T copy constructor
    }

    S(const S& that) {
        std::cout << "copy ctor" << "\n";
        _t = new T;
        *_t = *(that._t); // deep copy
    }

    S& operator=(const S& that) {
        std::cout << "copy assignment op" << "\n";
        *_t = *(that._t);
        return *this;
    }

    S(S&& that) {
        std::cout << "move ctor" << "\n";
        _t = that._t;
        that._t = nullptr;
    }

    S& operator=(S&& that) {
        std::cout << "move assignment op" << "\n";
        _t = that._t;
        that._t = nullptr;
        return *this;
    }
};

int main(int argc, char *argv[]) {
    std::cout << "\nDEFAULT" << "\n";
    S s0; // default ctor
    
    T t1{41, 42, 43};
    S s1{t1}; // init instance ctor

    std::cout << "\nCOPY" << "\n";

    S s2{s1}; // copy ctor
    auto s3 = s2; // copy ctor
    
    s2 = s1; // copy assignment op

    std::cout << "\nMOVE" << "\n";
        
    S s4{static_cast<S&&>(s3)}; // move ctor
    S s5 = static_cast<S&&>(s3); // move ctor

    s2 = static_cast<S&&>(s1); // move assignment op
    
    return 0;
}

