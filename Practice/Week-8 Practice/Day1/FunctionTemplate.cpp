#include <iostream>

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    int x = 10, y = 20;
    double a = 5.5, b = 3.2;

    std::cout << "Integer Sum: " << add<int>(x, y) << '\n';
    std::cout << "Double Sum: " << add<double>(a, b) << '\n';

    return 0;
}
