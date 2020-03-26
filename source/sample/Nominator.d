module sample.Nominator;

import sample.SCPDriver;

import std.stdio;

public extern (C++) class Nominator : VSCPDriver
{
    extern (C++):

    public override void f1(int value)
    {
        writeln("Hello from a f1 method in Nominator!");
    }

    public override void f2(int value)
    {
        writeln("Hello from a f2 method in Nominator!");
    }
}
