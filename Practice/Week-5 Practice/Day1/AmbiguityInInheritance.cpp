#include <iostream>

class English {
public:
    void greet() {
        std::cout << "Hello\n";
    }
};

class Japanese {
public:
    void greet() {
        std::cout << "Konnichiwa\n";
    }
};

class Derived : public English, public Japanese{
    int a;
};

int main() {
    English obj1;
    Japanese obj2;
    Derived obj3;
    // obj3.greet(); error: is ambigious
    return 0;
}