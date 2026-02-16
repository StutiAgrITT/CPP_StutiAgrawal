#include <iostream>
#include <string>

class Base {
public:
    std::string name;

    Base(std::string n) : name(n) {}

    virtual void show() const {
        std::cout << "Base: " << name << std::endl;
    }
};

class Derived : public Base {
public:
    int age;

    Derived(std::string n, int a) : Base(n), age(a) {}

    void show() const override {
        std::cout << "Derived: " << name << ", Age: " << age << std::endl;
    }
};

void display(Base obj) {  // Passed by value : slicing happens
    obj.show();
}

int main() {
    Derived d("Stuti", 21);

    display(d);  
    // Only Base part copied : Derived part sliced

    return 0;
}
