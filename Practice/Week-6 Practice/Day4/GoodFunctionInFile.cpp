#include <iostream>
#include <fstream>

int main() {
    std::ifstream obj("test.txt");
    std::cout << obj.good() << '\n';
    std::cout << obj.eofbit << '\n';
    std::cout << obj.badbit << '\n';
    std::cout << obj.failbit << '\n';
    std::cout << obj.goodbit << '\n';
    std::cout << (bool) obj << '\n'; // same result as good, better to use
    obj.close();
    return 0;
}