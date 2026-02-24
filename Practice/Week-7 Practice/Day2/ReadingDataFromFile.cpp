#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("files/hello.txt", std::ios::out);
    std::string line;
    while (std::getline(file, line)) { //dont use !file.eof() bcs it only becomes false after failed read, could cause double newline print or garbage
        std::cout << line << '\n';
    }
    file.close();
}
