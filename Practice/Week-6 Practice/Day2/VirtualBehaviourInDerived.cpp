#include <iostream>

class C1 {
public:
    void print() {
        std::cout << "1\n";
    }
};

class C2 : public C1 {
public:
    void print() {
        std::cout << "2\n";
    }
};

class C3 : public C2 {
public:
    void print() {
        std::cout << "3\n";
    }
};

