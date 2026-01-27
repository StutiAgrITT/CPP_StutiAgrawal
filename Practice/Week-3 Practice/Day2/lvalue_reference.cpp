#include <iostream>

struct {
    int num;
    int& ref = num;
} CombinedSize;

int main() {
    int num = 5;
    int& reference1 = num; //non const lvalue reference

    reference1 = 2; // num = 2
    std::cout << num << '\n';

    const int num2 = 5; 
    //int& reference2 = num2; //invalid bcs non const lvalue ref cant bind to non modifiable

    //int& reference3 = 5; //invalid bcs cant bind with rvalue

    double num4 = 6.3;
    // int& reference4 = num4; //invalid bcs int& cant reference to double (narrowing conversion)

    //double& reference5 = num; //invalid bcs it cant bind to rvalue
                              //(rvalue bcs it converts to double)

    int num5 = 10;
    reference1 = num5;
    //does not change the binding
    // changes value of num
    std::cout << num << '\n';

    int& reference6 = num5;
    int& reference7 = reference6; //also refers to num5
    reference7 = 23;
    std::cout << num5 << '\n';
    std::cout << sizeof(CombinedSize) + sizeof(num) << '\n';
    return 0;
}