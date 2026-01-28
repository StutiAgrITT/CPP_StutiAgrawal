#include <iostream>

int main() {
    int* ptr; //wild pointer
    std::cout << *ptr << '\n'; //prints whatever is at that memory
    std::cout << ptr << '\n'; // garbage value

    {
        int x = 5;
        ptr = &x; //contains address of x
        std::cout << *ptr << '\n'; //prints whatever is there
        std::cout << ptr << '\n';
    }
    *ptr = 10;  //dangling pointer
    std::cout << *ptr << '\n'; //undefined behaviour
    std::cout << ptr << '\n'; // still contains that address, prints whatever is there

    int* ptr2 = nullptr; //initialized with null
    // std::cout << *ptr // would give segmentation fault (trying to dereference a null pointer)

    return 0;
}