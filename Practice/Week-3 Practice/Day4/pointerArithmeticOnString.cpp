#include <iostream>


//pointer arithmetic doesnt work on strings unlike char arrays
//use str.c_str() that returns const char* to string's buffer
int main() {
    std::string name[] = {"ravi", "ravindra", "ravindra saini"};
    std::cout << *(name + 1) << '\n'; //prints name[1]
    std::cout << (name->c_str() + 1) << '\n'; //pointer moves one step forward on name[0], prints avi
    std::cout << *((name + 2)->c_str() + 7) << '\n'; //prints 7th char of name[2]
    std::cout << name[2][7] << '\n'; // same as above
    return 0;
}