#include<iostream>

// factorial program to practice 
int Factorial(int number) {
    if(number == 1) return 1;
    return number * Factorial(number - 1);
}

int main(){
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    std::cout << "Factorial of " << number << " is " << Factorial(number) << std::endl;
    return 0;
}
