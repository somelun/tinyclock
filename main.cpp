#include "tinyclock.h"
#include <thread>

int main(int argc, char* argv[]) {
    TINYCLOCK_NAME("external");
        std::this_thread::sleep_for(std::chrono::milliseconds(111));
    {
        TINYCLOCK_NAME("internal");
        std::this_thread::sleep_for(std::chrono::milliseconds(222));
    }
    return 0;
}

