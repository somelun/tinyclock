# tinyclock

This is super simple single-header profile macros definition.  
I always was writing it every time, then desided to just create it once and use when I need this.  
Example of usage can be found in main.cpp which is just this code:  

```cpp
#include "tinyclock.h"
#include <thread>

int main(int argc, char* argv[]) {
    TINYCLOCK_NAME("external");
    std::this_thread::sleep_for(std::chrono::milliseconds(111));
    
    // other block
    {
        TINYCLOCK_NAME("internal");
        std::this_thread::sleep_for(std::chrono::milliseconds(222));
    }
    return 0;
}
```  
