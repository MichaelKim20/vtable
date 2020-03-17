module sample.SCPDriver;

extern(C++, `stellar`):

public abstract class SCPDriver
{
    ~this() {}

    abstract void f1(int value);
    abstract void f2(int value);
    void f3(int value) {}
}
