#include <iostream>

void print(int i) {
    std::cout << i << ' ';
}

int main() {
    for (int i = 0; i < 10; i++) {
        print(i);
    }
}