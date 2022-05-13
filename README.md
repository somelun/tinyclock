# tinyclock

This is super simple single-header profile macros definition. After writing it few times I desided to just commit it once and use when I need.  
Im **master** branch I keep only inlude file **tinyclock.h**, because I plan to always use it as git submodule  
Example of usage can be found in **dev** branch in main.cpp which is just this:  

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
