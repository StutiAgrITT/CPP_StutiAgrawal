#include <iostream>

int main() {
    int arr[] = {1,2,3,4,5};
    int& ref = *arr;
    std::cout << *(&ref + 1) << '\n'; //will give 2
    return 0;
}