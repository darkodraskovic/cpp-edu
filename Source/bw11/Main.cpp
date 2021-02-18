#include<iostream>
#include <ostream>
#include <string>

using namespace std;

class Rational {
private:
    int _n = 0;
    int _d = 1;
public:
    Rational(int numerator = 0, int denonimator = 1) : _n(numerator), _d(denonimator) {
        std::cout << "Default constructor." << "\n";

    };
    Rational(const Rational& rhs) : _n(rhs._n), _d(rhs._d) {
        std::cout << "Copy constructor." << "\n";

    }; // copy constructor
    ~Rational() {};

    int numerator() const { return _n; }
    int denominator() const { return _d; }
    Rational& operator=(const Rational &);
    operator std::string() const; // conversion operator overload
};

Rational& Rational::operator =(const Rational& rhs) {
    if (this != &rhs) {
        _n = rhs.numerator();
        _d = rhs.denominator();
    }
    return *this;
}

Rational::operator std::string() const {
    if (_d == 1) return std::to_string(_n);
    else return std::to_string(_n) + "/" + std::to_string(_d);
}

Rational operator + (const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.numerator() * rhs.denominator() + lhs.denominator() * rhs.numerator(),
        lhs.denominator() * rhs.denominator());
}

Rational operator - (const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.numerator() * rhs.denominator() - lhs.denominator() * rhs.numerator(),
        lhs.denominator() * rhs.denominator());
}

Rational operator * (const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.numerator() * rhs.numerator(),
        lhs.denominator() * rhs.denominator());
}

Rational operator / (const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.numerator() * rhs.denominator(),
        lhs.denominator() * rhs.numerator());
}

// std::ostream& operator << (std::ostream& o, const Rational& r) {
//     if(r.denominator() == 1) return o << r.numerator();
//     else return o << r.numerator() << '/' << r.denominator();
// }

std::ostream& operator << (std::ostream& o, const Rational& r) {
    return o << std::string(r);
}

int main(int argc, char *argv[]){
    Rational a = 7;
    cout << "a is " << a << endl;
    
    Rational b(5,3);
    cout << "b is " << b << endl;
    
    Rational c = b; // copy constructor
    cout << "c is " << c << endl;
    
    Rational d;
    cout << "d is " << d << endl;
    
    d = c; // assignment operator (no constructor called)
    cout << "d is " << d << endl;

    Rational& e = d; // reference (no constructor called)
    cout << "e is " << e << endl;

    d = e; // assignment to self!
    cout << "d is " << d << endl;

    string s = "Rational value is ";
    s += b;
    cout << s << endl;
    
    return 0;
}
