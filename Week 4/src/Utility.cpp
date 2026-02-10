#include "Utility.h"
#include <iostream>

Utility* Utility::instance = nullptr;

Utility::Utility() {
    _logger = Logger::getInstance();
}

Utility* Utility::getInstance() {
    if (instance == nullptr) {
        instance = new Utility();
    }
    return instance;
}

double Utility::getValidDouble() {
    double number;

    while (true) {
        std::cin >> number;

        if (std::cin.fail()) {
            std::cin.clear();
            while (std::cin.get() != '\n');
            _logger->printMessage(_logger->MSG_INVALID_DOUBLE);
            continue;
        }
        if (std::cin.peek() != '\n') {
            while (std::cin.get() != '\n');
            _logger->printMessage(_logger->MSG_INVALID_DOUBLE);
            continue;
        }
        return number;
    }
}

int Utility::getValidPositiveInteger() {
    double number;

    while (true) {
        number = getValidDouble();
        if (number != (int) number || number < 1) {
            _logger->printMessage(_logger->MSG_INVALID_INTEGER);
            continue;
        }
        return (int) number;
    }
}

void Utility::showMenu() {
    std::cout << "\n==============================\n";
    std::cout << "Matrix Menu";
    std::cout << "\n==============================\n";
    std::cout << "1. Addition\n";
    std::cout << "2. Multiplication\n";
    std::cout << "3. Exit\n";
    std::cout << "==============================\n";
    std::cout << "Enter you choice: ";
}
