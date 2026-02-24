#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("files/file2.txt");
    int x;
    while (file >> x) {
        std::cout << x << ' ';
    }
    std::cout << "\nafter loop\n";
    file.clear();
    std::string s;
    file >> s;
    std::cout << s << '\n';
    return 0;
}