#include <iostream>

void findSize(int arr[]) {
    std::cout << sizeof(arr) << '\n'; //will give size of ptr, bcs arr decays to ptr in parameter
}

int main() {
    int arr[5]{0};
    findSize(arr);
    return 0;
}