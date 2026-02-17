#include <iostream>

class Base {
public:
    int id{4};
};

class Derived : public Base {
public:
    int id{5};
};

int main() {
    Derived d;
    Base b;
    std::cout << d.id << '\n';
    std::cout << b.id << '\n';
    std::cout << d.Base::id << '\n';
    return 0;
}
