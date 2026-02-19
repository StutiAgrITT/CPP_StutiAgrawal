#include <fstream>
#include <iostream>

int main() {
    //method 1: constructor
    std::ofstream obj1("TextFiles/test1.txt"); // we can write (name, mode), mode can be ios::out or in, mainly used when created object using fstream
    //method 2: function
    std::ofstream obj2;
    obj2.open("TextFiles/test2.txt");

    obj1 << "today is a great day\n";
    int a = 10;
    obj1 << "value of a is " << a << '\n';
    obj1.close();
    obj2.close();
    return 0;
}