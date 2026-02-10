#include <iostream>
#include <string>

class A {
public:
    virtual std::string getName() {return "A"; }
};
class B final: public A {
public:
    std::string getName() override { return "B"; }
};
//class C : public B {}; //error: cant use final class as base class