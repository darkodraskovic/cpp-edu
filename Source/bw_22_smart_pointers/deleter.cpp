#include "strc.h"
#include "utils.h"
#include <memory>

void demo_deleter() {
    message("create shared ptr a");
    std::shared_ptr<strc> a(new strc("thing a"), deleter);
    disp(a);

    a.reset();
    disp(a);

    message("create shared ptr b");
    std::shared_ptr<strc> b(new strc("thing b"), deleter);

    message("out of scope");
}
