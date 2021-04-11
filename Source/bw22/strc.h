#pragma once

#include <cstddef>

constexpr const char* __strc_class = "strc";
constexpr const char* __strc_version = "1.1";
constexpr size_t _maxlen = 10240;

class strc {
    char* data = nullptr;
    void msg(const char*);

public:
    strc();
    strc(const char* s);
    strc(const strc&);
    strc(strc&&);
    ~strc();

    const char* value() const;
    void swap(strc &);

    strc& operator=(strc);
    operator const char* () const;
};
