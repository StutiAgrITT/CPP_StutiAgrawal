#include <iostream>

template<class T1, class T2>
class MyClass {
public:
    T1 data1;
    T2 data2;
    void display() {
        std::cout << data1 << " " << data2 << '\n';
    }
};

int main() {
    MyClass<int, char> obj1;
    MyClass<double, bool> obj2;
    obj1.data1 = 4;
    obj1.data2 = 'a';
    obj2.data1 = 4.5;
    obj2.data2 = true;

    obj1.display();
    obj2.display();
    return 0;
}
