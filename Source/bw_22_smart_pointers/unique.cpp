#include "strc.h"
#include "utils.h"
#include <cstdlib>
#include <iostream>
#include <memory>

// can't call by value with unique ptr, so use ref as param
void f_unique(std::unique_ptr<strc>& p){
    std::cout << "f_unique(): ";
    disp(p);
}

void demo_unique() {
    message("create unique pointer one");
    std::unique_ptr<strc> a(new strc("one"));
    disp(a);
    
    message("make_unique two");
    auto b = std::make_unique<strc>("two");
    disp(a);
    f_unique(b);

    message("reset a to three");
    a.reset(new strc("three"));
    disp(a);
    disp(b);

    // can't copy unique ptr, but can move it
    message("move b to c");
    auto c = std::move(b);
    disp(a);
    disp(b);
    disp(c);

    message("reset a");
    a.reset();
    disp(a);
    disp(b);
    disp(c);

    // release dissociates ptr from obj without destroying obj
    message("release c");
    delete c.release();
    disp(a);
    disp(b);
    disp(c);
}
