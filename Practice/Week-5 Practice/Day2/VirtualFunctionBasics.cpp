#include <iostream>
#include <string>

class Base {
public:
    virtual std::string getName() { return "Base"; }
};

class Derived : public Base {
public:
    std::string getName() { return "Derived"; }
};

int main() {
    Derived d;
    Base& b = d;
    std::cout << b.getName() << '\n';
    return 0;
}