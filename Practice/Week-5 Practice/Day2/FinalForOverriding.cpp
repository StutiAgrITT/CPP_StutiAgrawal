#include <iostream>
#include <string>

class A {
public:
	virtual std::string getName() { return "A"; }
};
class B : public A{
public:
	//use of final specifier on following line -- that makes this function not able to be overridden in derived classes
	std::string getName() override final { return "B"; } // okay, overrides A::getName()
};
class C : public B{
public:
	//std::string getName() override { return "C"; } // compile error: overrides B::getName(), which is final
};
