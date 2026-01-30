#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int arr[n]{1,2,3,4,5};
    std::cout << sizeof(arr) << '\n';
    std::cout << 4[arr] << '\n'; //4[arr] = *(4 + arr) = *(arr + 4) = arr[4]
    std::cout << arr << '\n';
    return 0;
}