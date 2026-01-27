#include <iostream>

//saw this question on stack overflow
//this program is to check the different or same addresses
//given by reference and variables

void test(int a,int & x, int g, int h)
{
    std::cout << &a << "\n";
    std::cout << &x << "\n";
    std::cout << &g << "\n";
    std::cout << &h << "\n";
}

int main()
{
    int y = 6;
    int &z = y;
    int k = 43;
    test(2,y,5,78);
    std::cout << &y << "\n";
    std::cout << &z << "\n";
    std::cout << &k << "\n";
}

