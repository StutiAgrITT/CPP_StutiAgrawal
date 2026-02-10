#include <iostream>
#include <string>

class A
{
public:
    virtual std::string getName() const { return "A"; }
};

class B: public A
{
public:
    // note: no virtual keyword in B, C, and D
    std::string getName() const { return "B"; }
};

class C: public B
{
public:
    std::string getName() const { return "C"; }
};

class D: public C
{
public:
    std::string getName() const { return "D"; }
};

int main()
{
    C c {};
    B& rBase{ c }; // note: rBase is a B this time
    std::cout << rBase.getName() << '\n';
    //will print C
    //ONCE A FUNCTION IS VIRTUAL IN A BASE CLASS, IT STAYS VIRTUAL FOREVER DOWN THE INHERITANCE CHAIN
    return 0;
}