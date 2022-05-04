#pragma once

#include <iostream>

namespace tinyclock {

struct timer {
    timer(const char* timer_name) {
        name = timer_name;
        std::cout << name << std::endl;
    }
    ~timer() {
        std::cout << name << std::endl;
    }
private:
    const char* name = nullptr;
};

}

#define TINYCLOCK_NAME(name) tinyclock::timer __timer(name)
#define TINYCLOCK TINYCLOCK_NAME(__PRETTY_FUNCTION__)

