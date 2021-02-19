#include<iostream>
#include <ostream>

class num {
    int value = 0;
    public:
    num(int x = 0) : value(x) {}
    int getvalue() const {return value;}
    void setvalue(int x) {value = x;}
    num& operator ++();
    num operator++(int);
    num& operator --();
    num operator --(int);
};

num& num::operator++() {
    std::cout << "pre-increment: ";
    value += 1;
    return *this;
}

num num::operator++(int){
    std::cout << "pos-increment: ";
    num tmp = *this;
    value += 1;
    return tmp;
}

num& num::operator--() {
    std::cout << "pre-decrement: ";
    value -= 1;
    return *this;
}

num num::operator--(int){
    std::cout << "post-decrement: ";
    num tmp = *this;
    value -= 1;
    return tmp;
}

std::ostream& operator <<(std::ostream& o, const num& n) {
    return o << n.getvalue();
}

int main(int argc, char *argv[]){

    num n(42);
    std::cout << n << "\n";
    std::cout << ++n << "\n";
    std::cout << n << "\n";

    num m(42);
    std::cout << m << "\n";
    std::cout << m++ << "\n";
    std::cout << m << "\n";
    
    return 0;
}
