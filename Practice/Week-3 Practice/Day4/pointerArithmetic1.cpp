#include <iostream>

int main() {
    int* arr = new int[5]{10, 20, 30, 40, 50};
    int *ptr = arr;
    int **ptrptr = &ptr;

    (*ptrptr)++; //ptr pinting to next element
    (*(*ptrptr))++; //incrementing value at ptr

    std::cout << *ptr << '\n'; //21
    return 0;
}