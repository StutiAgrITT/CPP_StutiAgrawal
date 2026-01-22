#include <iostream>
#include "../include/input.hpp"

double getValidNumber() {
    double number;
    while (true) {
        std::cin >> number;

        if (std::cin.fail()) {
            std::cin.clear();
            while (std::cin.get() != '\n');
            std::cout << "Invalid input. Please enter again: ";
            continue;
        }
        if (std::cin.peek() != '\n') {
            while (std::cin.get() != '\n');
            std::cout << "Invalid input. Please enter again: ";
            continue;
        }
        return number;
    }
}

int getValidChoice() {
    double number;
    while (true) {
        number = getValidNumber();
        if (number != (int) number || number < 1 || number > 5) {
            std::cout << "Invalid input. Please enter from given choices: ";
            continue;
        }
        return (int) number;
    }
}
