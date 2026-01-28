#include <iostream>

void checkDecay(int arr[5]) { //will give warning it'll return size of ptr
    std::cout << "Inside function: " << sizeof(arr) << '\n';
}

int main() {
    int arr[5]{5, 4, 3, 2, 1};
    std::cout << "before decay: " << sizeof(arr) << '\n';
    int* ptr = arr;
    std::cout << "after decay: " << sizeof(ptr) << '\n';
    checkDecay(arr);

    return 0;
}