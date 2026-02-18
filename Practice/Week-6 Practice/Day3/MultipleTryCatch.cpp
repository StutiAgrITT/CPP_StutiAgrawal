#include <iostream>
#include <cmath>

double findSqrt(int x) {
    try {
        if (x < 0) throw "cant find sqrt of negative\n"; // throws exception
        return std::sqrt(x); 
    }
    catch (const char* e){
        std::cerr << e;
        throw "sorry\n"; //thrown to caller 
    }
}

int main() {
    int num;
    std::cin >> num;
    try {
        std::cout << findSqrt(num) << '\n';
    }
    catch (const char* e){ // caught here (in caller function)
        std::cerr << e;
    }
}