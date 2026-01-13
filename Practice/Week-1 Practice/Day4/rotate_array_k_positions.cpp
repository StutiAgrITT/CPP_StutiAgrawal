#include<iostream>

//shift the array by k postions
//meaning first k numbers should be moved to last maintaining the order
//slight modification of lc-189

void Reverse(int array[], int start, int end) {
    while (start < end) {
        int temporary = array[start];
        array[start] = array[end];
        array[end] = temporary;
        start++;
        end--;
    }
}

void RotateByKPositions(int array[], int size, int k) {
    Reverse(array, 0, k - 1);
    Reverse(array, k, size - 1);
    Reverse(array, 0, size - 1);
}

int main() {
    int size;
    std::cout << "Enter size: ";
    std::cin >> size;
    int array[size];
    std::cout << "Enter elements of array: " << std::endl;
    for (int i = 0; i < size; i++) {
        std::cin >> array[i];
    }
    int shift;
    std::cout << "Enter number by which array elements will be shifted: ";
    std::cin >> shift;
    RotateByKPositions(array, size, shift);
    std::cout << "Array after shifting: " << std::endl;
    for (int i = 0; i < size; i++) { 
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}