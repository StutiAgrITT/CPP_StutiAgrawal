#include "../include/divide.hpp"

extern "C" double divide(double num1, double num2, int* error) {
    if(num2 == 0) {
        *error = 1;
        return 0;
    }
    *error = 0;
    return num1 / num2;
}
