#include "strc.h"
#include "utils.h"

void demo_shared() {
    message("make_shared<>()");
    auto a = std::make_shared<strc>("one");
    // disp_shared() prints val and use_count()
    disp(a);

    message("shared_ptr<>");
    std::shared_ptr<strc> b(new strc("two"));
    disp(b);

    message("reset a");
    a.reset(new strc("three"));
    disp(a);

    message("copy a five times");
    auto x1 = a;
    auto x2 = a;
    auto x3 = a;
    auto x4 = a;
    auto x5 = a;
    disp(a);

    message("reset copies of a");
    x1.reset();
    x2.reset();
    x3.reset();
    x4.reset();
    x5.reset();
    disp(a);

    message("copy a");
    auto c = a;
    disp(a);
    disp(c);

    message("out of scope call to dtors");
}
