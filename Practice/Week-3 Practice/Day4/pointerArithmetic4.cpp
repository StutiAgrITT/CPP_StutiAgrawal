#include <iostream>

int main() {
    char arr[] = "INTIMETEC";
    char* p = arr;

    std::cout << *p++ << '\n'; //I, points to 1st
    std::cout << (*(p + 2) = p[3]) << '\n'; //M, "INTMMETEC"
    std::cout << (*(p + 3) = p[-1]) << '\n'; //I, "INTMIETEC"
    std::cout << *++p << '\n'; //T, points to 2nd
    std::cout << (*p++ = *arr + 2) << '\n'; //K, points to 3rd "INKMIETEC"
    std::cout << ++*p++ << '\n'; //N, points to 4th
    std::cout << ++p - arr << '\n'; //5
    std::cout << arr << '\n'; //INKNIETEC
    return 0;
}