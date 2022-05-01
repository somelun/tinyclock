#pragma once

#include <iostream>

#define TINYCLOCK_NAME(name)                    \
    struct __clock {                            \
        const char* t = nullptr;                \
        __clock(const char* str) {              \
            t = str;                            \
            std::cout << t << std::endl;        \
        }                                       \
        ~__clock() {                            \
            std::cout << "~" << t << std::endl; \
        }                                       \
    } __temp(name)

#define TINYCLOCK TINYCLOCK_NAME(__PRETTY_FUNCTION__)
