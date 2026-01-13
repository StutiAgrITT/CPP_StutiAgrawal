#include<iostream>

//returns nth number in fibonacci sequence
int Fibonacci(int number) {
    if (number == 0) return 0;
    if (number == 1) return 1;
    return Fibonacci(number - 1) + Fibonacci(number - 2);
}

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    std::cout << "Number at position " << number << " in fibonacci sequence is " << Fibonacci(number - 1) << std::endl;
    return 0;
}