#include "exponent.h"

int power(int a) {      // different definition - multiple definition - linker error
    return a * a * a;
}