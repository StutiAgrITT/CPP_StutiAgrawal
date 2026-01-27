#include <iostream>
#include <string>

int main() {
    std::string originalString = "hello, world";
    std::string newString;

    std::cout << "Original string: " << originalString << "\nNew String: " << newString << '\n';
    
    newString = std::move(originalString);
    
    std::cout << "Original string: " << originalString << "\nNew String: " << newString << '\n'; 
}