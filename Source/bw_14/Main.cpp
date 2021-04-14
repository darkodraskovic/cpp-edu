#include <cstdio>
#include<iostream>

class MultBy {
    int mult = 1;
    MultBy();
public:
    MultBy(int n) : mult(n) {};
    int operator ()(int n) const { return mult * n;}
};

int main(int argc, char *argv[]){
    const MultBy times4(4);
    const MultBy times10(10);
    const MultBy times15(15);
    
    std::printf("%d\n", times4(15));
    std::printf("%d\n", times10(15));
    std::printf("%d\n", times15(15));
    
    return 0;
}
