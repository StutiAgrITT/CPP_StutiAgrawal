#include <iostream>

class Animal {
protected:
    std::string _name;
public:
    Animal(std::string name) {
        _name = name;
    }
    virtual void speaks() = 0;
};

class Cow : public Animal {
public:
    Cow(std::string name) : Animal(name){}
    void speaks() {
        std::cout << _name << "says Moo\n";
    }
};

class Cat : public Animal {
public:
    Cat(std::string name) : Animal(name){}
    void speaks() {
        std::cout << _name << "says Meow\n";
    }
};

// void func(Animal a) {} // error

int main() {
    //Animal a("Bob"); //error
    Cow c("Betsy");
    Animal& a = c;
    return 0;
}