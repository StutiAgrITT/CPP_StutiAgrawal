#include <iostream>
#include <fstream>

int main() {
    std::ifstream obj("TextFiles/test2.txt"); 
    char ch;
    while (obj) { //we can use obj.eof(), but this works. how? good function
        obj.get(ch);
        std::cout << ch; // or we can use cout << obj.get()
    }
    obj.clear();
    obj.seekg(0);
    std::string word;
    while (!obj.eof()) {
        obj >> word;
        std::cout << word << ' ';
    }

    obj.clear();
    obj.seekg(0);

    char word2[10];
    while(!obj.eof()) {
        obj.read(word2, 10); // need to use c style string
        std::cout << word2;
    }
    obj.close();
}
