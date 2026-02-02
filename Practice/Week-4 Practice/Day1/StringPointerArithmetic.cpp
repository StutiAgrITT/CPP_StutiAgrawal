#include <iostream>

int main() {
    char* s[] = {"apple", "carrot", "date", "banana"};
    char** ptr[] = {s, s + 3, s + 1, s + 2};
    char*** p = ptr;

    std::cout << (*--*++p + 2) << '\n';
    std::cout << (p + 3 - (ptr + 1)) << '\n';
    return 0;
}