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
        std::cout << name << ": " << format_time(diff.count()) << std::endl;
    }

    std::string format_time(const double& time) const {
        char buffer[256];
        if (time < 1e-6) {
            sprintf(buffer, "%8.2lfns", 1e9 * time);
        } else if (time < 1e-3) {
            sprintf(buffer, "%8.2lfus", 1e6 * time);
        } else if (time < 1) {
            sprintf(buffer, "%8.2lfms", 1e3 * time);
        } else {
            sprintf(buffer, "%8.2lfs ", time);
        }

        return std::string(buffer);
    }

private:
    const char* name = nullptr;
    time_t start;
};

}

#define TINYCLOCK_NAME(name) tinyclock::timer __timer(name)
#define TINYCLOCK TINYCLOCK_NAME(__PRETTY_FUNCTION__)

