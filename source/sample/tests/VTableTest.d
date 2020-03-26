module sample.tests.VTableTest;

import sample.SCPDriver;
import sample.Nominator;

import std.stdio;

extern(C++) ulong doVTest1 ();
extern(C++) ulong doCheckMethodPoint ();

unittest
{
    doVTest1();

    assert(doCheckMethodPoint() == 0);

    //auto n = new Nominator();

    //void **vtable = n.getVtable();
/*
    writefln("n.__vptr : %s", n.__vptr);
    writefln("n.__vptr[0] = %s %s", n.__vptr[0], vtable[0]);
    writefln("n.__vptr[1] = %s %s", n.__vptr[1], vtable[1]);
    writefln("n.__vptr[2] = %s %s", n.__vptr[2], vtable[2]);
    writefln("n.__vptr[3] = %s %s", n.__vptr[3], vtable[3]);
    writefln("n.__vptr[3] = %s %s", n.__vptr[4], vtable[4]);
    writefln("n.__vptr[3] = %s %s", n.__vptr[5], vtable[5]);
    writefln("n.__vptr[3] = %s %s", n.__vptr[6], vtable[6]);
    writefln("n.__vptr[3] = %s %s", n.__vptr[7], vtable[7]);
*/
    //writefln("n.getVtable() : %s", vtable);
    writefln("cast(void*)(&n.f1) : %s", cast(void*)(&(Nominator.f1)));
    writefln("cast(void*)(&n.f2) : %s", cast(void*)(&(Nominator.f2)));
}
