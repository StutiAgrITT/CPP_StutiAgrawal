#include <iostream>

void isNull(int* ptr) {
    if (ptr == nullptr) {
        std::cout << "Null pointer\n";
    }
    else {
        std::cout << "Not a null pointer\n";
    }
}

int main() {
    int* ptr; //wild ptr
    //std::cout << *ptr << '\n'; //if uncommented, it will give not a nullptr for ptr
    int* ptr2 {}; // null ptr
    int* ptr3 = nullptr; // null ptr

    isNull(ptr);
    isNull(ptr2);
    isNull(ptr3);
    return 0;
}