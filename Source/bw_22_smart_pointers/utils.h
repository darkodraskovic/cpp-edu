#pragma once

#include <memory>
#include "strc.h"

void message(const char *s);
void disp(std::unique_ptr<strc>& o);
void disp(std::shared_ptr<strc> &o);
void disp(std::weak_ptr<strc>& o);
void deleter(const strc* o);
