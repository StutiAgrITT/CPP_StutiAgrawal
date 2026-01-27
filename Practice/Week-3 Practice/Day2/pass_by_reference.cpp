#include <iostream>

void function(int value, int& reference) {
    std::cout << "Inside function" << '\n';
    std::cout << "Address of value: " << &value << '\n'; //diff bcs it is a copy
    std::cout << "Address of reference: " << &reference << '\n';
    value++; //remains only in copy
    reference++;
}

int main() {
    int value = 1;
    int& reference = value;
    std::cout << "Outside function" << '\n';
    std::cout << "Address of value: " << &value << '\n';
    std::cout << "Address of reference: " << &reference << '\n';
    function(value, reference);
    std::cout << "Value: " << value << '\n';
    return 0;
}