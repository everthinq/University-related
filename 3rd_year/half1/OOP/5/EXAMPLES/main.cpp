#include "ex1.h"
#include "ex2.h"


void EXAMPLE1()
{
    B1 *b = new B1();
    b->foo();
    b->bar();
    delete b;
}

void EXAMPLE2()
{
    C c;
       c.f();
       c.g();
       c.toB();
       c.f();
       c.g();
}

int main()
{
    EXAMPLE1(); cout << "\n";

    EXAMPLE2();

    return 0;
}
