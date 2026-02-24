#include <iostream>
#include <fstream>

int main() {
    std::fstream file("files/file3.txt", std::ios::in | std::ios::out);
    char ch;
    file >> ch;
    file << 'X';
    // acc to standards, get and put are not synchronous. put doesnt move on reading.
    // but in most implementation, put moves. hence this will do 1X345 instead of X2345

    file.close();

    std::ifstream in("files/file3.txt");
    std::string s;
    getline(in, s);
    std::cout << s << '\n';
    return 0;
}