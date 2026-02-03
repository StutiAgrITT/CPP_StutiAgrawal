#include <iostream>

class MyClass {
private:
    int m_num1;
    int m_num2;

public:
    MyClass(int num1, int num2) {
        std::cout << "Object created, Constructor called\n";
        m_num1 = num1;
        m_num2 = num2;
    }

    void print() {
        std::cout << m_num1 << " " << m_num2 << '\n';
    }
};

int main() {
    MyClass obj {'a', true};
    obj.print();
    return 0;
}