#include<iostream>

//this program is to check return values for '=' operator
int main() {
    int x{5};
    std::cout << (x = 10) << std::endl;
    //x = 10 will return 10
    return 0;
}