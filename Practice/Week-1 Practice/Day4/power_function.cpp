#include<iostream>

//recursive function to calculate power of a number
int CalculatePower(int base, int power) {
    if (power == 0) return 1;
    return base * CalculatePower(base, power - 1);
}

int main() {
    int base;
    int power;
    std::cout << "Enter base: ";
    std::cin >> base;
    std::cout << "Enter power: ";
    std::cin >> power;
    std::cout << base << " to the power " << power << " is " << CalculatePower(base, power) << std::endl;
    return 0;
}
