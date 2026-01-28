#include <iostream>

void nullify(int*& ptr) {
    ptr = nullptr;
}

int main() {
    int x = 10;
    int* ptr = &x;
    std::cout << ((ptr) ? "Not Null" : "Null") << '\n';
    nullify(ptr);
    std::cout << ((ptr) ? "Not Null" : "Null") << '\n';
    return 0;
}