#include <iostream>

int operations(int x, int *ptrToY, int **ptrToPtrToZ) {
    int y, z;
    **ptrToPtrToZ += 1; // c = 5
    z = **ptrToPtrToZ; //z = 5;
    *ptrToY += 2; // c = 7;
    y = *ptrToY; // y = 7
    x += 3; //x = 7
    return x + y + z;
}

int main() {
    int c, *b, **a;
    c = 4;
    b = &c;
    a = &b;
    std::cout << operations(c, b, a) << '\n';
    return 0;
}