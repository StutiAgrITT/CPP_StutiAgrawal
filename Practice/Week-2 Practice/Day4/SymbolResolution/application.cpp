#include "calculate.h"

//the linking would be successful if linked together with calculate.cpp
//but if not, it would give undefined reference
//linker maps undefined symbol here (multiply) to the defined one
int main() {
    int x = multiply(3, 4);
    return x;
}