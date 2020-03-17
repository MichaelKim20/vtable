
#include <stdio.h>
#include <string.h>
#include "SCPDriver.h"

using namespace stellar;

#define VTABLESIZE(T) unsigned long long vtableSize ( T &value ) {\
    long **vtable = (long **)&value;\
    int idx = 0;\
    size_t count = 0;\
    for (idx = 0; ; idx++)\
    {\
        if (vtable[0][idx] == NULL)\
            break;\
        count++;\
    }\
    return count;\
}\

VTABLESIZE(SCPDriver)
