#include <iostream>
#include "Logger.h"
#include "ValidInput.h"

double getValidDouble() {
    double number;
    while (true) {
        std::cin >> number;

        if (std::cin.fail()) {
            std::cin.clear();
            while (std::cin.get() != '\n');
            printMessage(MSG_INVALID_DOUBLE);
            continue;
        }
        if (std::cin.peek() != '\n') {
            while (std::cin.get() != '\n');
            printMessage(MSG_INVALID_DOUBLE);
            continue;
        }
        return number;
    }
}

int getValidPositiveInteger() {
    double number;
    while (true) {
        number = getValidDouble();
        if (number != (int) number || number < 1) {
            printMessage(MSG_INVALID_INTEGER);
            continue;
        }
        return (int) number;
    }
}
