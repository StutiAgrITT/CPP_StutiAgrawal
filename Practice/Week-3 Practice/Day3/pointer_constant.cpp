#include <iostream>

int main() {
    int x = 5;
    int y = 6;

    const int* ptr1 = &x; // const value
    ptr1 = &y; // allowed
    // *ptr1 = 3; //not allowed
    x = 10; y = 11; //still allowed

    const int z = 15;
    //int* ptr2 = z; //not allowed
    
    int* const ptr3 = &x;
    *ptr3 = 15; //allowed
    // ptr3 = &y; //not allowed

    const int* const ptr4 = &x;
    // *ptr4 = 20; //not allowed
    // ptr4 = &y; // not allowed

    return 0;
}