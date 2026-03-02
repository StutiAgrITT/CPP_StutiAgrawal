#include <iostream>
#include <cstring>

template <typename T>
int compare(T a, T b) {
    if (a > b) return 1;
    if (a < b) return -1;
    return 0;
}

template <>
int compare<const char*>(const char* a, const char* b) {
    int result = std::strcmp(a, b);

    if (result > 0) return 1;
    if (result < 0) return -1;
    return 0;
}

int main() {
    std::cout << "Int: " << compare(10, 5) << std::endl;
    std::cout << "Equal Int: " << compare(3, 3) << std::endl;
    std::cout << "String Literal: " << compare("apple", "banana") << '\n';

    return 0;
}