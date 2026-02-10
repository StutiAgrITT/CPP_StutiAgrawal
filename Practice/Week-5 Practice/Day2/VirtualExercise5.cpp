#include <iostream>
#include <string>

class A
{
public:
    virtual std::string getName() const { return "A"; } //this is const
};

class B: public A
{
public:
    virtual std::string getName(){ return "B"; } //these are not const
};

class C: public B
{
public:
    virtual std::string getName(){ return "C"; }
};

class D: public C
{
public:
    virtual std::string getName() { return "D"; }
};

int main()
{
    C c {};
    A& rBase{ c };
    std::cout << rBase.getName() << '\n';
    //this will print A.
    //bcs A has getName const, rest dont, so they are treated as different functions. B and C getNames are not overrides.
    //similarly, if A didn't have const, B and C did, then also A would have been called.
    //if A and B didnt, but C had const, then B would have been printed, as it woud be the closest

    return 0;
}