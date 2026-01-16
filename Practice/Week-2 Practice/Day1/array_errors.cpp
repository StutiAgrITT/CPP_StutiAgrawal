#include<iostream>

//this program is to see whether cpp gives
//array out of bounds exception (it doesnt)

int main() {
    int array[] = {1, 2, 3, 4, 5};
    std::cout << *(array + 2) << '\n';
    std::cout << *(array + 5) << '\n';     //undefined behaviour
    std::cout << array[100000] << '\n';    // segmentation fault
}