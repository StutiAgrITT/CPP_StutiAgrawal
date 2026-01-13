#include<iostream>

// reversing number using recursive function and static variable
int ReverseNumber(int number) {
    static int reversed_number = 0;
    if (number == 0) return reversed_number;
    reversed_number = reversed_number * 10 + (number % 10);
    return ReverseNumber(number / 10);
}

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    std::cout << "Reversed: " << ReverseNumber(number) << std::endl;
    return 0;
}