module sample.SCPDriver;

extern(C++, `stellar`):

public abstract class VSCPDriver
{
    ~this() {}
    abstract void f1(int value);
    abstract void f2(int value);
    void ** getVtable() {return null;};
}
