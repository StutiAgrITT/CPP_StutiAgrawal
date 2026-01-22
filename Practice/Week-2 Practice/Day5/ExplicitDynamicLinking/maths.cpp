#include<iostream>

extern "C" {

int addNumbers(int num1, int num2) {
    return num1 + num2;
}

int multiplyNumbers(int num1, int num2) {
    return num1 * num2;
}

void printHello() {
    std::cout << "Hello from library!\n";
}

}