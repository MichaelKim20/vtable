module sample.main;

import sample.Nominator;
import sample.SCPDriver;

import std.stdio;

template virtualMethodCount(T)
{
    size_t c()
    {
        size_t result;
        foreach (member; __traits(allMembers, T))
            static if (is(typeof(__traits(getMember, T, member))))
            {
                foreach (overload; __traits(getOverloads, T , member))
                    result += __traits(isVirtualMethod, overload);
            }
        return result;
    }
    enum objectVmc = 4; // toHash, opCmp, opEquals, toString
    enum virtualMethodCount = c() - objectVmc;
}

void main()
{
    //auto s = new SCPDriver();

    // Let's get going!
    writeln("Hello World!");
    auto n = new Nominator();
    n.f1(1);
    n.f2(1);
    n.f3(1);
    writefln("%s", n.__vptr);
    int count = 0;
    for (int idx = 0; ; idx++)
    {
        if (n.__vptr[idx] == null)
            break;
        count++;
    }

    writeln("Pointer to f1() in N's vtable: ", n.__vptr[5]);
    //auto tempvptr = n.__vptr;
    //tempvptr.f1(1);
    writefln("Nominator : %d", count);
}
