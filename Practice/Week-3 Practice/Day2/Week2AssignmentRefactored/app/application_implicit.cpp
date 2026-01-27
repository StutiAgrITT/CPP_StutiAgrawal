#include <iostream>

#include "add.hpp"
#include "subtract.hpp"
#include "multiply.hpp"
#include "divide.hpp"
#include "input.hpp"
#include "menu.hpp"

void processChoice(int choice) {
    double num1, num2, result;
    int error;

    std::cout << "Enter first operand: ";
    num1 = getValidNumber();
    std::cout << "Enter second operand: ";
    num2 = getValidNumber();

    switch (choice) {
    case 1:
        result = add(num1, num2);
        break;
    case 2:
        result = subtract(num1, num2);
        break;
    case 3:
        result = multiply(num1, num2);
        break;
    case 4:
        result = divide(num1, num2, &error);
        if (error) {
            std::cout << "Can't divide by zero.\n";
            return;
        }
        break;
    default:
        std::cout << "Invalid input. Please enter from given choices: ";
    }
    std::cout << "Result: " << result << '\n';
}

int main() {
    int choice;
    while (true) {
        showMenu();
        choice = getValidChoice();

        if (choice == 5) break;
        processChoice(choice);
    }
    return 0;
}
