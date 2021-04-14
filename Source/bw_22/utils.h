#pragma once

#include <memory>
#include "strc.h"

void message(const char *s);
void disp_unique(std::unique_ptr<strc>& o);
void disp_shared(std::shared_ptr<strc> &o);
void disp_weak(std::weak_ptr<strc>& o);
