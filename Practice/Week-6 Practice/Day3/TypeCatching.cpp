#include <iostream>

int main() {
    try {
        throw -1; //will work if explicitly type casted
    }
    // catch (int x) {
    //     std::cerr << "caught an int\n";
    // }
    catch (double x) { //DOES NOT CONVERT TO DOUBLE, NO IMPLICIT CONVERSION
        std::cerr << "caught a double\n";
    }
    return 0;
}