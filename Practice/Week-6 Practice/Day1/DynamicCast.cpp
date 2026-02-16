#include <iostream>

class Base {
public:
    virtual ~Base() {}  // Must have at least one virtual function
};

class Derived : public Base {
public:
    void show() {
        std::cout << "Derived object" << std::endl;
    }
};

int main() {
    Base* basePtr = new Derived();

    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);

    if (derivedPtr) {
        derivedPtr->show();
    } else {
        std::cout << "Cast failed" << std::endl;
    }

    delete basePtr;
    return 0;
}
