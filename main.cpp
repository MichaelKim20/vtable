#include <cstdlib>
#include <cstdio>
#include <cstring>

class Foo {
    public:
        virtual void v()
        {
            printf("Hello from a VIRTUAL method in Foo!\n");
        }
};

class FooBar : public Foo {
    public:
        virtual void v()
        {
            printf("Hello from a VIRTUAL method in FooBar!\n");
        }
};

template <class T>
size_t countVtableOf(T* a)
{
    static_assert(a != NULL);

    long **vtable = (long **)a;
    int idx = 0;
    size_t count = 0;
    for (idx = 0; ; idx++)
    {
        if (vtable[0][idx] == NULL)
            break;
        count++;
    }
    return count;
}


int main(int argc, char **argv)
{
    FooBar foobar;
    Foo foo;

    foobar.v();     // FooBar::v()

    Foo *fooptr = (Foo *)&foobar;
    fooptr->v();    // FooBar::v()

    printf("---------\n");

    // FooBar is just a pointer to the FooBar vtable.
    // Foo is just a pointer to the Foo vtable.
    printf("sizeof(foobar) = %lu, sizeof(foo) = %lu\n", sizeof(foobar), sizeof(foo));

    long *foobarAsLong = (long *)&foobar;
    long *fooAsLong = (long *)&foo;
    printf("FooBar vtable pointer: %p\n", foobarAsLong[0]);
    printf("Foo vtable pointer: %p\n", fooAsLong[0]);

    long **foobarVtable = (long **)&foobar;
    long **fooVtable = (long **)&foo;

    // This is the address of FooBar::v()
    printf("First entry of FooBar VTABLE: %p\n", foobarVtable[0][0]);
    // This is the address of  Foo::v()
    printf("First entry of Foo VTABLE: %p\n", fooVtable[0][0]);

    int idx;
    size_t count;

    count = countVtableOf(&foobar);
    printf("Length of FooBar VTABLE: %lu\n", count);
    for (idx = 0; idx < count; idx++)
    {
        printf("%dst entry of FooBar VTABLE: %p\n", idx+1, foobarVtable[0][idx]);
    }

    count = countVtableOf(&foo);
    printf("Length of Foo VTABLE: %lu\n", count);
    for (idx = 0; idx < count; idx++)
    {
        printf("%dst entry of Foo VTABLE: %p\n", idx+1, fooVtable[0][idx]);
    }
}