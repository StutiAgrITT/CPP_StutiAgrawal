#include <iostream>

void printReference(const int& y) // y is a const reference
{
    std::cout << y << '\n';
}

int main() {
    int x = 5;
    printReference(x);   // ok: x is a modifiable lvalue, y binds to x

    const int z = 5;
    printReference(z);   // ok: z is a non-modifiable lvalue, y binds to z

    printReference(5);   // ok: 5 is rvalue literal, y binds to temporary int object

    return 0;
}