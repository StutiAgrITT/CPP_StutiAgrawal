#include <iostream>

class Base {
public:
    Base(int x, int y) {
        std::cout << "Base constructor called with: "
                  << x << " and " << y << std::endl;
    }
};

class DerivedA : virtual public Base {
public:
    DerivedA() : Base(1, 2) {
        std::cout << "DerivedA constructor\n";
    }
};

class DerivedB : virtual public Base {
public:
    DerivedB() : Base(3, 4) {
        std::cout << "DerivedB constructor\n";
    }
};

class MostDerived : public DerivedA, public DerivedB {
public:
    MostDerived() : Base(100, 200) {
        std::cout << "MostDerived constructor\n";
    }
};

int main() {
    MostDerived obj;
    return 0;
}
