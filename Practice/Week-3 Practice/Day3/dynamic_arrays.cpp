#include <iostream>

int main() {
    std::size_t size; //size_t bcs unsigned, doesnt allow negative
    // but if entered a small negative value it will still throw bad_array_new_length exception
    // because it would be of a  very large size
    std::cin >> size;
    //int arr[size]; //not allowed in standard c++
    std::cout << size << '\n';
    int* arr = new int[size];

    std::cout << sizeof(arr) << '\n'; //will give size of pointer

    delete[] arr; //[] tells this is array, clear multiple elements
}