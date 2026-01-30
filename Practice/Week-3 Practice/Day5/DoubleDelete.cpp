#include <iostream>

int main() {
    int* arr = new int[5];
    delete[] arr;
    //delete[] arr; // runtime: will give double free detected
    arr = nullptr;
    delete[] arr; //no problem
    std::cout << "Hello\n";
    return 0;
}