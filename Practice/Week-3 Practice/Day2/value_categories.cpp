#include <iostream>

int main() {
    std::cout << std::boolalpha;
    std::cout << "int   : " << std::is_lvalue_reference<int>::value << " " 
    << std::is_rvalue_reference<int>::value << '\n';
    std::cout << "int&  : " << std::is_lvalue_reference<int&>::value << " " 
    << std::is_rvalue_reference<int&>::value << '\n';
    std::cout << "int&& : " << std::is_lvalue_reference<int&&>::value << " " 
    << std::is_rvalue_reference<int&&>::value << '\n';

    return 0;
}