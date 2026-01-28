#include <iostream>

void pass_by_value(std::string str) {
    std::cout << "Pass by value: " << str << '\n';
    str[4] = 'y';
}

void pass_by_reference(std::string& str) {
    std::cout << "Pass by reference: " << str << '\n';
    str[0] = 'y';
}

void pass_by_address(std::string* str) {
    std::cout << "Pass by address: " << *str << '\n';
    (*str)[1] = 'o';
}

int main() {
    std::string str = "hello";
    pass_by_value(str);
    pass_by_reference(str);
    pass_by_address(&str);
    std::cout << str << '\n';
    return 0;
}