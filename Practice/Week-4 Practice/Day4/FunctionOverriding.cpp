#include <iostream>

class Base {
public:
    void show() {
        std::cout << "Base show\n";
    }
};

class Derived : public Base {
public:
    void show() {
        std::cout << "Derived show\n";
    }
};

int main() {
    Base* b = new Derived();
    b->show();   // Derived show
    delete b;
}
