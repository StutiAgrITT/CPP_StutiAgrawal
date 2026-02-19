#include <iostream>
#include <fstream>

int main() {
    std::fstream obj;
    obj.open("TextFiles/test2.txt", std::ios::app);
    std::string str = "how are you?\n";
    for (char c : str) {
        obj.put(c); // using put, char by char
    }

    std::string str2 = "my name is stuti\n";
    obj.write(str2.c_str(), 10); //using write, number of chars copied
    obj << " Stuti\n"; // using << 
    obj.close();
}