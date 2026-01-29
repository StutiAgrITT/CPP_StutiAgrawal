#include <iostream>

int main() {
    int num = 5;
    int arr[3] = {31, 32, 33};
    int* ptr = nullptr;

    ptr = &num;

    *ptr = 15; // num = 15
    ptr = &arr[2];
    *(&arr[1] + 1) += 3; //arr[2] = 36
    std::cout << num << '\n';
    std::cout << arr[0] << '\n';
    std::cout << arr[1] << '\n';
    std::cout << arr[2] << '\n';
    return 0;
}