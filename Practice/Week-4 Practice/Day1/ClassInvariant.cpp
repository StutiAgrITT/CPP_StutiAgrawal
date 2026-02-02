#include <iostream>

struct Fraction {
    int numerator = 0;
    int denominator = 1; // class invariant: should not be zero
};

void printFractionValue(const Fraction& f) {
    std::cout << f.numerator / f.denominator << '\n';
}

int main() {
    Fraction f {5, 0};
    printFractionValue(f); //cause error
}