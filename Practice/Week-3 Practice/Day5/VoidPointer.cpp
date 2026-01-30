#include <iostream>

enum Type {
    tInt,
    tFloat,
    tCString
};

void printVoid(void* ptr, Type type) {
    switch (type) {
    case Type::tInt:
        std::cout << *static_cast<int*>(ptr) << '\n';
        break;
    case Type::tFloat:
        std::cout << *static_cast<float*>(ptr) << '\n';
        break;
    case Type::tCString:
        std::cout << static_cast<char*>(ptr) << '\n';
        break;
    default:
        std::cerr << "invalid type provided\n";
        break;
    }
}

int main() {
    int nValue = 5;
    float fValue = 7.5;
    char szValue[] = "Hello";

    printVoid(&nValue, tInt);
    printVoid(&fValue, tFloat);
    printVoid(szValue, tCString);
}
