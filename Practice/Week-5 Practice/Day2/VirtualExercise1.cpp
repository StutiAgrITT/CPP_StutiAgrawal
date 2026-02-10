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
    virtual std::string getName() const { return "B"; }
};

class C: public B
{
public:
// no getName() function here
};

class D: public C
{
public:
    virtual std::string getName() const { return "D"; }
};

int main()
{
    C c;
    A& rBase = c ;
    std::cout << rBase.getName() << '\n';
    //this will print B. rBase is reference of A pointing to C. A::getname() is
    //virtual hence it will call the morst derived matching function between A and C
    return 0;
}