#include <iostream>

int main() {
    int a = 4, b = 6, c = 9;
    int *ptr1 = &a; //ptr1 points to a
    int* ptr2 = ptr1; //ptr2 points to a

    ptr1 = &b; //ptr1 points to b
    a++; //5
    (*ptr2)++; //a = 6

    b = *ptr2 * 2; //12
    c = *ptr2 + *ptr1; //18

    std::cout << a << '\n';
    std::cout << b << '\n';
    std::cout << c << '\n';
    return 0;
}