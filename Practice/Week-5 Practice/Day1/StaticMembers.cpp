#include <iostream>

class Demo {
public:
    int x;
    static int count; //cant initiialize here
    Demo() {
        count++;
    }
};

int Demo::count = 0;

int main() {
    std::cout << Demo::count << '\n';
    Demo obj1;
    std::cout << obj1.count << '\n';
}