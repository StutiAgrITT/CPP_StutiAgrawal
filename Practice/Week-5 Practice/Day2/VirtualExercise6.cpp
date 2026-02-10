#include <iostream>
#include <string>

class A
{
public:
	A() { std::cout << getName() << '\n';} // addition of constructor (getName() now called from here)

	virtual std::string getName() const { return "A"; }
};

class B : public A
{
public:
	virtual std::string getName() const { return "B"; }
};

class C : public B
{
public:
	virtual std::string getName() const { return "C"; }
};

class D : public C
{
public:
	virtual std::string getName() const { return "D"; }
};

int main()
{
	C c;

	return 0;
}