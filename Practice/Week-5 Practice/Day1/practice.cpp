#include <iostream>

struct Base { virtual void f(){std::cout<<"Base\n";} };
struct Derived: Base { void f(){std::cout<<"Derived\n";} };
 
void test(Base b){ b.f(); }
void test(Base* b){ b->f(); }
 
int main()
 
{
    Derived d;
    test(d);
    return 0;
}