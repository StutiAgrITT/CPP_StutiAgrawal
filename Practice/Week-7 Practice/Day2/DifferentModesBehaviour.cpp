#include <iostream>
#include <fstream>

int main() {
    std::fstream file("files/hello.txt", std::ios::app | std::ios::in | std::ios::out);
    file.seekp(0);
    std::cout << file.tellp() << '\n'; //0
    file << "Hello";
    std::cout << file.tellg() << '\n'; //5 bcs append, but can move backwards.
    file.seekg(0);
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << '\n';
    }
    return 0;
}