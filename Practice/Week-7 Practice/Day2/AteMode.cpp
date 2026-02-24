#include <iostream>
#include <fstream>

int main() {
    std::ofstream file("files/hello.txt", std::ios::ate);
    std::cout << file.tellp() << '\n'; // will be zero
    file.seekp(0); // matters
    std::cout << file.tellp() << '\n';
    file << "Hello";
    return 0;
}