#include <iostream>
#include <cstdio>
#include <memory>
#include <utility>

#include "unique.cpp"
#include "shared.cpp"
#include "weak.cpp"
#include "deleter.cpp"

int main(int argc, char *argv[]) {
    // demo_unique();
    // demo_shared();
    // demo_weak();
    demo_deleter();
    
    return 0;
}
