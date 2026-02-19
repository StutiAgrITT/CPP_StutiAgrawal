#include <iostream>
#include <fstream>

int main() {
    std::ofstream o1("TextFiles/Country.txt");
    o1 << "India\n";
    o1 << "Australia\n";
    o1 << "USA\n";
    o1 << "Canada\n";

    std::ofstream o2("TextFiles/Country.txt");
    o2 << "hello\n";
    o2 << "hello\n";
    o2 << "hello\n";
    o2 << "hello\n";
}
