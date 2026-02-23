#include <iostream>

void crashFunction() {
    int* ptr = nullptr;
    std::cout << *ptr << '\n';
}

int main() {
    crashFunction();
    return 0;
}
