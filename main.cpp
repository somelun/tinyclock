#include "tinyclock.h"

int main(int argc, char* argv[]) {
    TINYCLOCK_NAME("external");
    {
        TINYCLOCK_NAME("internal");
    }
    return 0;
}

