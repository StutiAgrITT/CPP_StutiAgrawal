#include <iostream>

int main() {
    int* valuePtr = new(std::nothrow) int;  //nothrow used to avoid crashing program if failure
                                            //and equating to nullptr
    if (!valuePtr) {
        std::cerr << "Memory allocation failed!\n";
    }
    else {
        std::cout << "Memory allocated successfully: " << valuePtr << '\n';
    }
}