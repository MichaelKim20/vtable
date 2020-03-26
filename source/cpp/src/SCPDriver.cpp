#include "SCPDriver.h"

namespace stellar
{

    void **
    VSCPDriver::getVtable()
    {
        void **pvftable = (void **)(*(long *)this);
        printf("In C++ [0] %p\n", pvftable[0]);
        printf("In C++ [1] %p\n", pvftable[1]);
        printf("In C++ [2] %p\n", pvftable[2]);
        printf("In C++ [3] %p\n", pvftable[3]);


        auto bfunc1 = &VSCPDriver::f1;
        printf("In C++ f1 : %d\n", (long)reinterpret_cast<void *&>(bfunc1));
        auto bfunc2 = &VSCPDriver::f2;
        printf("In C++ f2 : %d\n", (long)reinterpret_cast<void *&>(bfunc2));
        return pvftable;
    }

    void
    VTestSCPDriver::f1(int value)
    {
        printf("Hello from a f1 method in SCPDriver!(%d)\n", value);
    }

    void
    VTestSCPDriver::f2(int value)
    {
        printf("Hello from a f2 method in SCPDriver!(%d)\n", value);
    }

    void
    VTestSCPDriver::f3(int value)
    {
        printf("Hello from a f3 method in VTestSCPDriver!(%d)\n", value);
    }
}
