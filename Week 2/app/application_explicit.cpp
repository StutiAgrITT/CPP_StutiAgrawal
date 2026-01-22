#include <iostream>
#include <dlfcn.h>

#include "../include/menu.hpp"
#include "../include/input.hpp"

typedef double (*opType)(double, double);
typedef double (*divideType)(double, double, int*);

void processChoice(int choice, opType add, opType subtract, 
                   opType multiply, divideType divide) {
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
    void *lib_handle = dlopen("./lib/libmathops.so", RTLD_LAZY);
    if (!lib_handle) {
        std::cout << "Error: " << dlerror() << '\n';
        return 1;
    }

    opType add = (opType) dlsym(lib_handle, "add");
    opType subtract = (opType) dlsym(lib_handle, "subtract");
    opType multiply = (opType) dlsym(lib_handle, "multiply");
    divideType divide = (divideType) dlsym(lib_handle, "divide");

    int choice;
    while (true) {
        showMenu();
        choice = getValidChoice();

        if (choice == 5) break;
        processChoice(choice, add, subtract, multiply, divide);
    }
    dlclose(lib_handle);
    return 0;
}
