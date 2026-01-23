#include <iostream>

int main() {
    int array[] = {10, 20, 30, 40, 50};
    int *ptr = array;
    int **ptrToPtr = &ptr;

    (*ptrToPtr)++;  //moves ptr to first index
    (*(*ptrToPtr))++; //increments value at first index;
    std::cout << *ptr << '\n';
    return 0;
}