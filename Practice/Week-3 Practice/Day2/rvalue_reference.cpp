#include <iostream>

int main() {
    std::string s1 = "Hello, ";
    std::string s2 = "World!\n";

    std::string temp = s1 + s2; //temp has own memory, lives till end of scope
    std::string s3 = temp; //s3 has separate memory, uses copy constructor - diff obj, diff add
    std::string& s4 = temp; //only alias for temp, no new memory, same add
    std::string&& s5 = std::move(temp); //move casts temp as rvalue, no move constructor called, move converts to rvalue, alias for temp
    std::string&& s6 = s1 + s2; //s1 + s2 creates temp, s6 binds to that temp, no new memory (diff add acc to temporary)
    std::cout << temp.size() << " " << '\n';
    std::string s7 = std::move(temp); // uses move constructor, temp empty, s7 new memory new address
    std::cout << "temp: " << &temp << '\n';
    std::cout << "s3: " << &s3 << '\n';
    std::cout << "s4: " << &s4 << '\n';
    std::cout << "s5: " << &s5 << '\n';
    std::cout << "s6: " << &s6 << '\n';
    std::cout << "s7: " << &s7 << '\n';
    std::cout << temp.size() << " " << '\n'; //0 bcs we have moved the contents
}