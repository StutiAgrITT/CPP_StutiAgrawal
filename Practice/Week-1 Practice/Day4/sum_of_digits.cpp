#include<iostream>

//recursive function to calculate sum of digits
int SumOfDigits(int number) {
    if(number == 0) return 0;
    return (number % 10) + SumOfDigits(number / 10);
}

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    std::cout << "Sum of digits of " << number << " is " << SumOfDigits(number) << std::endl;
    return 0;
}