#include <iostream>

// This exercise was mentioned in the quiz of learncpp chapter 14.3

struct IntPair {
    int num1;
    int num2;

    void print() {
        std::cout << "Pair(" << num1 << ", " << num2 << ")\n";
    }

    bool isEqual(IntPair pair) {
        return (num1 == pair.num1) && (num2 == pair.num2);
    }
};

int main()
{
	IntPair p1 {1, 2};
	IntPair p2 {3, 4};

	std::cout << "p1: ";
	p1.print();

	std::cout << "p2: ";
	p2.print();

	std::cout << "p1 and p1 " << (p1.isEqual(p1) ? "are equal\n" : "are not equal\n");
	std::cout << "p1 and p2 " << (p1.isEqual(p2) ? "are equal\n" : "are not equal\n");

	return 0;
}