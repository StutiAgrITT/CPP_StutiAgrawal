#include <iostream>

template <typename T1, typename T2 = int>

class Demo {
public:
    T1 data1;
    T2 data2;
    Demo(T1 a, T2 b) {
        data1 = a;
        data2 = b;
    }
    void display() {
        std::cout << data1 << " " << data2 << '\n';
    }
};

int main() {
    Demo<char> obj('a', 5);
    obj.display();
    return 0;
}