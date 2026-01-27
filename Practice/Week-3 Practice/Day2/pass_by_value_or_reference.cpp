#include <iostream>
#include <string>

#define isSmall(T) (sizeof(T) <= 2 * sizeof(void*))

struct S
{
    double a;
    double b;
    double c;
};

void passByValueOrReference(bool isSmall) {
    if (isSmall) {
        std::cout << "Use pass by value" << '\n';
    }
    else {
        std::cout << "Use pass by reference\n";
    }
}

int main()
{
    passByValueOrReference(isSmall(int));
    double d;
    passByValueOrReference(isSmall(d));
    passByValueOrReference(isSmall(S));
    std::string str = "hello";
    passByValueOrReference(isSmall(str));

    return 0;
}