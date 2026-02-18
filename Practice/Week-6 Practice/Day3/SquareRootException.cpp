#include <iostream>
#include <cmath>

int main() {
    int num;
    std::cin >> num;
    try {
        if (num < 0) throw "can't find sqrt of negative\n";
        std::cout << std::sqrt(num);
    }
    catch (const char* e){ // doesnt work without const as srting literal
        std::cerr << e;
    }
}