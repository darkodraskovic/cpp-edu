#include "strc.h"
#include "utils.h"

void f_unique(std::unique_ptr<strc>& p) {
    message("f()");
    disp_unique(p);
}

void demo_unique() {
    message("create unique pointer one");
    std::unique_ptr<strc> a(new strc("one"));
    disp_unique(a);
    f_unique(a);
    
    message("make_unique two");
    auto b = std::make_unique<strc>("two");
    disp_unique(a);
    disp_unique(b);

    message("reset a to three");
    a.reset(new strc("three"));
    disp_unique(a);
    disp_unique(b);

    message("move b to c");
    auto c = std::move(b);
    disp_unique(a);
    disp_unique(b);
    disp_unique(c);

    message("reset a");
    a.reset();
    disp_unique(a);
    disp_unique(b);
    disp_unique(c);

    message("release c");
    c.release();
    disp_unique(a);
    disp_unique(b);
    disp_unique(c);
}
