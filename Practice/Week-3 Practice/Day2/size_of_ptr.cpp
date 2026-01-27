#include <iostream>

int main() {
    char* ptr1;
    int* ptr2;
    double* ptr3;
    std::string* ptr4;

    std::cout << sizeof(ptr1) << '\n';
    std::cout << sizeof(ptr2) << '\n';
    std::cout << sizeof(ptr3) << '\n';
    std::cout << sizeof(ptr4) << '\n';
    //size of pointer doesnt depend on data type
    //depends on architecture
}