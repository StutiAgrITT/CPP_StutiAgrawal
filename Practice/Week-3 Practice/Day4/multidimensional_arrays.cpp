#include <iostream>

int main() {
    int rows = 7;
    int (*arr1)[5] = new int[rows][5];

    std::cout << "size of arr1: " << sizeof(arr1) << '\n'; // 8 bcs pointer
    std::cout << "size of arr1 row: " << sizeof(*arr1) << '\n'; // 20 bcs fixed array of 5
    
    int cols = 5;

    int** arr2 = new int*[rows];
    for(int row = 0; row < rows; row++) {
        arr2[row] = new int[cols];
    }

    std::cout << "size of arr2: " << sizeof(arr2) << '\n'; // 8 bcs pointer
    std::cout << "size of arr2 row: " << sizeof(*arr2) << '\n'; // 8 bcs pointer

    return 0;
}