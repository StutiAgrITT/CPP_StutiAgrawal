#include <iostream>

void function3() {
    int var = 10;
    std::cout << "this is " << var << '\n';
}

void function2() {
    int var = 20;
    std::cout << "hello " << var << '\n';
    function3();
}

void function1() {
    int var = 30;
    std::cout << "hi " << var << '\n';
    function2();
}

int main() {
    std::string name = "hello";
    function1();
    return 0;
}