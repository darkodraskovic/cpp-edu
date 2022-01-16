#include "strc.h"
#include "utils.h"
#include <memory>

void demo_weak() {
    message("make_shared<>()");
    auto a = std::make_shared<strc>("thing");
    auto c1 = a;
    auto c2 = a;
    auto c3 = a;
    auto c4 = a;
    auto c5 = a;

    message("ref count should be 6");
    disp(a);

    message("weak_ptr<>()");
    auto w1 = std::weak_ptr<strc>(a);
    disp(w1);

    message("destroy copies");
    c1.reset();
    c2.reset();
    c3.reset();
    c4.reset();
    c5.reset();
    disp(a);
    disp(w1);
    
    message("call dtors");
}
