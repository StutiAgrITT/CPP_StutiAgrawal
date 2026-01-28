#include <iostream>

int main() {
    int* ptr;
    {
        int x = 10;
        ptr = &x;
    }
    //ptr is dangling ptr after this scope ends 
    char* ptr2;
    ptr2 = (char*) ptr;
    char a = 'a';
    ptr2 = &a;
    std::cout << *ptr2 << '\n'; // 'a'
    std::cout << *ptr << '\n'; // ascii value of 'a'
    //said undefined bcs the memory it has might get allocated to something else
    return 0;
}