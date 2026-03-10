#include <iostream>

class Add {
public:
    int operator()(int a, int b) {
        return a + b;
    }
};

int main() {
    Add add;
    std::cout << add(3,4);
}