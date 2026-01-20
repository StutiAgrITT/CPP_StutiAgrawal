#include "math.h"

int add(int, int); //declaring for third time

int main() {
    return add(5, 3);
}

int add(int a, int b)  {  // defining only once
    return a + b;
}