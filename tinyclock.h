#pragma once

#include <iostream>

#define TINYCLOCK_NAME(name) \
    struct __clock { \
        __clock(const char* str) { \
            std::cout << name << std::endl; \
        } \
    } __temp(name)

#define TINYCLOCK TINYCLOCK_NAME(__PRETTY_FUNCTION__)
