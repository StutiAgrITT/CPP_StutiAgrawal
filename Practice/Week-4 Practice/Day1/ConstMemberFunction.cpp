#include <iostream>

struct Something {
    void print() {
        std::cout << "non const\n";
    }

    void print() const{
        std::cout << "const\n";
    }
};

int main() {
    Something s1;
    const Something s2;
    s1.print(); // will call non const
    s2.print(); // will cLl const
}