#include<iostream>

// array of size n will be given containing numbers from 1 to n except 1 which will be 0
// find the missing number
// lc - 268
int FindMissingNumber(int nums[], int size) {
    int actual_sum = 0;
    for(int i = 0; i < size; i++) {
        actual_sum += nums[i];
    }
    int expected_sum = (size * (size + 1)) / 2;
    return expected_sum - actual_sum;
}

int main() {
    int size;
    std::cout << "Enter size: ";
    std::cin >> size;
    int array[size];
    std::cout<< "Enter elements of array: " << std::endl;
    for(int i = 0; i < size; i++){
        std::cin >> array[i];
    }
    std::cout << "Missing number is: " << FindMissingNumber(array, size) << std::endl;
}
