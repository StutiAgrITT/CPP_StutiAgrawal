#include <iostream>

int main() {
    int a = 10, b = 0;

    int c;
    try {
        if (b == 0) throw "divide by zero error\n";
        c = a / b;
        std::cout << c << '\n';
    }
    catch (const char* e) {
        std::cout << "exception occured: " << e;
    }
    return 0;
}