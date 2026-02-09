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
public:
    void greet() {
        Japanese::greet(); //one way
    }

};

int main() {
    English obj1;
    Japanese obj2;
    Derived obj3;
    obj3.greet();
    obj3.English::greet(); //other way
    return 0;
}