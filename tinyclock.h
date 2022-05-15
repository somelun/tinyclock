#pragma once

#include <iostream>
#include <chrono>


namespace tinyclock {

typedef std::chrono::system_clock::time_point time_t;

struct timer {
    timer(const char* timer_name) {
        name = timer_name;

        start = std::chrono::system_clock::now();

    }

    ~timer() {
        time_t end = std::chrono::system_clock::now();
        std::chrono::duration<double> diff = end - start;
        std::cout << name << ": " << diff.count() << std::endl;
    }
private:
    const char* name = nullptr;
    time_t start;
};

}

#define TINYCLOCK_NAME(name) tinyclock::timer __timer(name)
#define TINYCLOCK TINYCLOCK_NAME(__PRETTY_FUNCTION__)

