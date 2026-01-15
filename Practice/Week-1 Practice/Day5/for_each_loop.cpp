#include<iostream>

int SumOfArray(int array[]) {
    int sum{};
    //doesnt work bcs here array is a pointer, not an array
    //compiler only sees a pointer, size is unknown
    // for(int num : array) {
    //     sum += num;
    // }
}

int main() {
    int array[] = {1, 2, 3, 4, 5};

    //works here bcs compiler knows the starting address and the size
    for(int num : array) {
        std::cout << num << " ";
    }
}