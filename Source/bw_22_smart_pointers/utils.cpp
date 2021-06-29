#include <cstddef>
#include <cstdio>
#include "utils.h"

void message(const char* s) {
    printf("\n%s\n",s);
    fflush(stdout);
}

// display obj val from unique ptr
void disp_unique(std::unique_ptr<strc>& o){
    if (o) puts(o->value());
    else puts("null");
    fflush(stdout);
}

void disp_shared(std::shared_ptr<strc>& o) {
    if (o) printf("%s (%ld)\n", o->value(), o.use_count());
    else puts("[null]");
    fflush(stdout);
}

void disp_weak(std::weak_ptr<strc>& o) {
    size_t count = o.use_count();
    if (auto sp = o.lock()) printf("%s (w:%ld s:%ld)\n", sp->value(), count, sp.use_count());
    else puts("[null]");
}
