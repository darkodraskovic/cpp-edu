#include<iostream>
#include "NumWord.h"

int main(int argc, char *argv[]){

    NumWord nw;
    
    // std::cout << nw.Words(0) << "\n";
    // std::cout << nw.Words(4) << "\n";
    // std::cout << nw.Words(10) << "\n";
    // std::cout << nw.Words(11) << "\n";
    // std::cout << nw.Words(20) << "\n";
    // std::cout << nw.Words(32) << "\n";
    // std::cout << nw.Words(99) << "\n";
    // std::cout << nw.Words(100) << "\n";
    // std::cout << nw.Words(101) << "\n";
    // std::cout << nw.Words(115) << "\n";
    // std::cout << nw.Words(122) << "\n";
    // std::cout << nw.Words(599) << "\n";
    // std::cout << nw.Words(1599) << "\n";
    // std::cout << nw.Words(17599) << "\n";
    // std::cout << nw.Words(171599) << "\n";
    // std::cout << nw.Words(3171599) << "\n";
    // std::cout << nw.Words(71599) << "\n";
    // std::cout << nw.Words(123071599) << "\n";
    // std::cout << nw.Words(87123071599) << "\n";
    // std::cout << nw.Words(10087123171599) << "\n";
    long n = 3; std::cout << n << " is "<< nw.Words(n) << "\n";
    n = 47; std::cout << n << " is "<< nw.Words(n) << "\n";
    n = 73; std::cout << n << " is "<< nw.Words(n) << "\n";
    n = 1492; std::cout << n << " is "<< nw.Words(n) << "\n";
    n = 10012; std::cout << n << " is "<< nw.Words(n) << "\n";
    n = 100073; std::cout << n << " is "<< nw.Words(n) << "\n";
    n = 1000000; std::cout << n << " is "<< nw.Words(n) << "\n";
    n = 123000000000; std::cout << n << " is "<< nw.Words(n) << "\n";
    n = 474142398123; std::cout << n << " is "<< nw.Words(n) << "\n";
    n = 1474142398123; std::cout << n << " is "<< nw.Words(n) << "\n";
    n = 999000000000000; std::cout << n << " is "<< nw.Words(n) << "\n";


    
    return 0;
}
