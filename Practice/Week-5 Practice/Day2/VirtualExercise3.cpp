#include <iostream>
#include <string>

class A
{
public:
    // note: no virtual keyword
    std::string getName() const { return "A"; }
};

class B: public A
{
public:
    virtual std::string getName() const { return "B"; }
};

class C: public B
{
public:
    virtual std::string getName() const { return "C"; }
};

class D: public C
{
public:
    virtual std::string getName() const { return "D"; }
};

int main()
{
    C c {};
    A& rBase{ c };
    std::cout << rBase.getName() << '\n'; // A as no virtual function there
    B& rBaseB = c;
    std::cout << rBaseB.getName() << '\n'; // C as there is virtual function

    return 0;
}