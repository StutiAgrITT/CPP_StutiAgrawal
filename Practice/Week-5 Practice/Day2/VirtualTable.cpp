#include <iostream>

class Person {
public:
    virtual void print1() { std::cout << "1. Person\n"; };
};
class Student : public Person {
public:
    void print1() override { std::cout << "1. Student\n"; };
    void print2() { std::cout << "2. Student\n"; }; // not virtual
};
class ResearchStudent : public Student{
public:
    void print2() { std::cout << "2. Research Student\n"; };
};

int main() {
    ResearchStudent r;
    Student& ref1 = r;
    Person& ref2 = r;
    ref1.print2();
    return 0;
}