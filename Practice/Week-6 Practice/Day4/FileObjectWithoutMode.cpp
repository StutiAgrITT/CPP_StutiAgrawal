#include <iostream>
#include <fstream>

int main() {
    std::fstream obj;
    obj.open("TextFiles/test2.txt");

    obj << "bye\n";
    obj.seekg(0);
    char c;
    while ((c = obj.get()) != EOF) {
        std::cout << c;
    }
    obj.close();
}