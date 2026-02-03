#include <iostream>

int main() {
    int a = 5;
    int* p = &a;
    int** q = &p;
    std::cout << a << '\n';
    std::cout << p << '\n';
    std::cout << q << '\n';
    //std::cout << *a << '\n';
    std::cout << *p << '\n';
    std::cout << *q << '\n';
    std::cout << &a << '\n';
    std::cout << &p << '\n';
    std::cout << &q << '\n';
    //std::cout << **p << '\n';
    std::cout << **q << '\n';
    return 0;
}