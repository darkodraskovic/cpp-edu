#include <cstddef>
#include <cstdio>
#include "utils.h"

void message(const char* s) {
    printf("\n%s\n",s);
    fflush(stdout);
}

// display obj val from unique ptr
void disp(std::unique_ptr<strc>& o){
    if (o) puts(o->value());
    else puts("null");
    fflush(stdout);
}

void disp(std::shared_ptr<strc>& o) {
    if (o) printf("val: %s; use count: %ld\n", o->value(), o.use_count());
    else puts("[null]");
    fflush(stdout);
}

void disp(std::weak_ptr<strc>& o) {
    size_t count = o.use_count(); // weak ptr count
    // must lock weak ptr in order to refer to its val
    if (auto sp = o.lock()) printf("val: %s; use count: w:%ld s:%ld\n", sp->value(), count, sp.use_count());
    else puts("[null]");
}

void deleter(const strc* o) {
    std::printf("deleter: ");
    if (o) {
        printf("%s\n", o->value());
        delete o;
    } else {
        std::printf("[null]\n");
    }
    fflush(stdout);
}
