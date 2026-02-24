#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("files/file1.txt");
    int x;
    while (!file.eof()) {
        file >> x;
        std::cout << x << ' '; // after 20, eof is still unset, only after failed read it will be set. so before that only we are printing x, x still contains 20
        // 10 20 20
    }
    std::cout << '\n';
    return 0;
}