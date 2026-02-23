#include <iostream>

int add(int x, int y) {
    int result = x + y;
    return result;
}

int main() {
    int a = 5;
    int b = 10;
    int c = add(a, b);
    std::cout << "Sum: " << c << '\n';
    return 0;
}
