//first base then second
#include <iostream>

class English {
public:
    English() {
        std::cout << "English\n";
    }
    void greet() {
        std::cout << "Hello\n";
    }
};

class Japanese {
public:
    Japanese() {
        std::cout << "Japanese\n";
    }
    void greet() {
        std::cout << "Konnichiwa\n";
    }
};

class Hindi {
public:
    Hindi(int x, int y) {
        std::cout << "Hindi\n";
    }
    void greet() {
        std::cout << "Pranam\n";
    }
};

class Derived : public Japanese, public English{ //first japanese will be called, then first
public:
    Derived() {
        std::cout << "Derived\n";
    }
    void greet() {
        Japanese::greet();
    }

};

class Derived2 : public Hindi { 
public:
    Derived2() : Hindi(2, 4) {// have to give parameters here

    }
};

int main() {
    Derived obj3;
    Derived2 obj2;
    return 0;
}