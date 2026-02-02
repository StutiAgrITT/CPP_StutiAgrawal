#include <iostream>

int main() {
    std::string s1 = "1";    // constructor from const char*
    std::string s2 = s1;     // copy constructor
    std::string s3 = std::string("world"); // move constructor
    s1 = "hello";            // move assignment
    s2 = s1;                 // copy assignment
    s2 = std::move(s1);      // move assignment
}