#include <iostream>
#include <fstream>

int main() {
    std::fstream file("files/file1.txt", std::ios::in | std::ios::out);
    if (!file) {
        std::cout << "failed\n";
    }
    std::string line;
    getline(file, line);
    std::cout << line << '\n';
    std::cout << file.tellg();
    file.seekg(0);
    getline(file, line);
    std::cout << line << '\n';
    file.close();
    return 0;
}