#include <stdio.h>
#include <string.h>
#include <iostream>
#include "SCPDriver.h"

using namespace stellar;
using namespace std;

void doVTest1 ()
{
    printf("Test1\n");
    VTestSCPDriver object;

    object.f1(1);
    object.f2(2);
    object.f3(3);
    long **vtable = (long **)&object;
    unsigned long idx;
    for (idx = 0; vtable[0][idx] != 0; idx++);
    printf("count : %lu\n", idx);
}

class A
{
public:
    int n1 = 1;
    virtual ~A() {};
    void func1() { n1++; }
    virtual void vfunc1(){};
    virtual void vfunc2(){};
};

class B : public A
{
public:
    int n2 = 2;

    virtual ~B() {};
    void func2() { n2++; }
    virtual void vfunc3(){};
    virtual void vfunc4(){};
};

int doCheckMethodPoint ()
{
    B *table = new B();
    void **pvftable = (void **)(*(long *)table);

    auto bfunc1 = &B::vfunc1;
    if ((long)reinterpret_cast<void *&>(bfunc1) != 17)
        return 1;

    auto bfunc2 = &B::vfunc2;
    if ((long)reinterpret_cast<void *&>(bfunc2) != 25)
        return 9;

    auto bfunc3 = &B::vfunc3;
    if ((long)reinterpret_cast<void *&>(bfunc3) != 33)
        return 17;

    auto bfunc4 = &B::vfunc4;
    if ((long)reinterpret_cast<void *&>(bfunc4) != 41)
        return 25;

    printf("B.vfunc1    :   %d\n", &B::vfunc1);
    printf("B.vfunc2    :   %d\n", &B::vfunc2);
    printf("B.vfunc3    :   %d\n", &B::vfunc3);
    printf("B.vfunc4    :   %d\n", &B::vfunc4);

    return 0;
}
