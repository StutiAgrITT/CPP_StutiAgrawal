#include <iostream>

//this program is compiled using diff versions of compiler

int main() {
    std::cout << __cplusplus << '\n';
    auto x = 10; // gives error when compiled with -std=c++98
    std::cout << x << '\n';
    return 0;
}