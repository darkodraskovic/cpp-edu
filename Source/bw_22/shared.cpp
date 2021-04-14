#include "strc.h"
#include "utils.h"

void demo_shared() {
    message("make_shared()");
    auto a = std::make_shared<strc>("one");
    disp_shared(a);

    message("shared_ptr<>");
    std::shared_ptr<strc> b(new strc("two"));
    disp_shared(b);

    message("reset a");
    a.reset(new strc("three"));
    disp_shared(a);

    message("copy a five times");
    auto x1 = a;
    auto x2 = a;
    auto x3 = a;
    auto x4 = a;
    auto x5 = a;
    disp_shared(a);

    message("reset copies of a");
    x1.reset();
    x2.reset();
    x3.reset();
    x4.reset();
    x5.reset();
    disp_shared(a);

    message("copy a");
    auto c = a;
    disp_shared(a);
    disp_shared(c);

    message("call dtors");
}
