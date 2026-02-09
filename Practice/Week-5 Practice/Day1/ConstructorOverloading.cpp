#include <iostream>

class Main{
private:
    int x;
    int y;
public:
    // Main() {
    //     std::cout << "hello\n";
    // }    // give more than one default constructor error
    Main(int x) {
        std::cout << "hello2\n";
    }
    Main(int x = 3, int y = 5) {
        std::cout << "hello3\n";
    }
};

int main() {
    Main obj;
    //Main obj(5); //gove error for more than one instance
    return 0;
}