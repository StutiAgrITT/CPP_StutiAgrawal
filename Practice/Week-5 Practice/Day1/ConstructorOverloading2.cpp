#include <iostream>

class Maths {
    int x;
    float y;
public:
    Maths(int x) {
        this->x = x;
        std::cout << "int\n";
    }
    Maths(float y) {
        this->y = y;
        std::cout << "float\n";
    }
};

int main() {
    Maths o1(1);
    //Maths o1(1.3); //error: matches more than one: narrowing conversion
}