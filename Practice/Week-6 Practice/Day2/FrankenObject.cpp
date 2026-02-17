#include <iostream>

class Base {
public:
    int _x;
    Base(int x) : _x(x){}
};

class Derived : public Base {
public:
    int _y;
    Derived(int x, int y) : Base(x), _y(y) {}
};

int main() {
    Derived d1(1, 2);
    Derived d2(3, 4);
    Base& b = d1;
    b = d2; // only the base part is copied(x), creates a franken object
    std::cout << d1._x << " " << d1._y << '\n';
    return 0;
}