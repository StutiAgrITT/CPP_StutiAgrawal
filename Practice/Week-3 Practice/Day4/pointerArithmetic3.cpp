#include <iostream>

int main() {
    int arr[6] = {1, 2, 3, 4, 5};
    int *p = arr;

    for (int i = 1; i < 6; i++) {
        *(arr + i) += *(arr + i - 1);
    } // {1, 3, 6, 10, 15, 15}

    for (int i = 0; i < 6; i++) std::cout << *(arr + i) << " ";
    std::cout << '\n';
    std::cout << *p++ << '\n'; //1, points to 1st index
    std::cout << p[2] << '\n'; //1st + 2: 3rd index: 10
    std::cout << (*p)++ << '\n'; //prints 3, {1,4,6,10,15, 15}
    std::cout << ++p[3] << '\n'; //increments 4th index, prints: 16
    std::cout << (*(p + 3))-- << '\n'; //prints 16, {1,4,6,10,15,15}
    std::cout << *--p << '\n'; //points to 0th, prints 1
    std::cout << *++p << '\n'; //points to 1st, prints 4
    return 0;
}