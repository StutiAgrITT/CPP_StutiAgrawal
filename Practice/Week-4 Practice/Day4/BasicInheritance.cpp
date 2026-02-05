#include <iostream>

class Animal {
public:
    void eat() {
        std::cout << "Animal eats\n";
    }
};

class Dog : public Animal {
public:
    void bark() {
        std::cout << "Dog barks\n";
    }
};

int main() {
    Dog d;
    d.eat();   // inherited
    d.bark();  // own
}
