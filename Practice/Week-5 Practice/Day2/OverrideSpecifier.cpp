#include <iostream>
#include <string>

//virtual exercise 5 problem
//not overriding which are meant to override bcs of different function signature

class A
{
public:
    virtual std::string getName() { return "A"; } //this is const
};

class B: public A
{
public:
    std::string getName() override { return "B"; } //these are not const
};

int main()
{
    B b {};
    A& rBase{ b };
    std::cout << rBase.getName() << '\n';


    return 0;
}