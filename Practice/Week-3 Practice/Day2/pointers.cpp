#include <iostream>

int main() {
    int x = 10;
    int& y = x;
    int* ptr = &x;

    std::cout << &x << '\n';
    std::cout << &y << '\n';
    std::cout << ptr << '\n'; //same for all 3
}