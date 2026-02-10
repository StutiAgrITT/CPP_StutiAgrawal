#include <iostream>

class Base {
public:
    virtual Base* getThis() {
        std::cout << "BaseClass\n";
        return this;
    }
};

class Derived : public Base{
public:
    Derived* getThis() override { //doesnt give error even with different types
        std::cout << "DerivedClass\n";
        return this;
    }
};

int main() {
    Derived d;
    Base b1;
    Base b2 = d; //obj slicing
    Base* b3 = &d; //base ptr to derived
    d.getThis(); //derived
    b1.getThis(); //base
    b2.getThis(); //base
    b3->getThis(); //derived
    return 0;
}
