#include <iostream>
#include <fstream>

int main() {
    std::ofstream file("files/hello.txt", std::ios::app);
    file.seekp(0); //doesnt matter
    std::cout << file.tellp() << '\n';
    file << "Hello";
    return 0;
}
