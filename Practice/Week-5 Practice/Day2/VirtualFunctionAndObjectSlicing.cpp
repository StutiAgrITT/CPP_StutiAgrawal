#include <iostream>

struct Base {virtual void f(){std::cout<<"Base\n";} };
struct Derived: Base { void f(){std::cout<<"Derived\n";} };
 
void test(Base b){ 
    std::cout << "without pointer\n";
    b.f(); }
void test(Base* b){ 
    std::cout << "with pointer\n";
    b->f(); }
 
int main()
 
{
    Derived d;
    Base b1 = d;
    Base* b2 = &d;

    test(d);
    test(b1);
    test(b2);
    std::cout << '\n';
    d.f();
    b1.f();
    b2->f();

    return 0;
}