#include <iostream>

int main() {
    int x = 5;
    void* ptr = &x;

    float* cFloatPtr = (float*) ptr;
    float* floatPtr = static_cast<float*>(ptr);
    int* intPtr = static_cast<int*>(ptr);
    std::cout << *cFloatPtr << '\n'; //gives undefined behaviour
    std::cout << *floatPtr << '\n'; //gives undefined behaviour
    std::cout << *intPtr << '\n';
    
    return 0;
}