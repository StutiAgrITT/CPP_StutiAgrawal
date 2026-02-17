#include <iostream>

class Base {
public:
    int num1;
    Base(int x) : num1{x} {}
    virtual Base& operator=(const Base& other) {
        num1 = other.num1;
        return *this;
    }
};

class Derived : public Base {
public:
    int num2;
    Derived(int x, int y) : Base(x), num2{y} {}
    Derived& operator=(const Base& other) override {
        Base::operator=(other);
        const Derived& derivedOther = dynamic_cast<const Derived&>(other);
        num2 = derivedOther.num2;
        return *this;
    }
};

int main() {
    Derived d1(1, 2);
    Derived d2(3, 4);
    Base& b = d1;
    b = d2;
    std::cout << d1.num1 << " " << d1.num2 << '\n';
    return 0;
}