#include <iostream>

class User
{
    int m_a;
    int m_b{};
public:
    User() {}  // user-defined
    void print() {
        std::cout << m_a << " " << m_b << '\n'; //garbage 0
    }
};

class Default
{
    int m_a;
    int m_b{};
public:
    Default() = default; //compiler-defined
    void print() {
        std::cout << m_a << " " << m_b << '\n'; //0 0
    }
};

int main() {
    User obj1{};
    Default obj2{}; //if default initialized instead of value, then will give garbage as well
    obj1.print();
    obj2.print();
    return 0;
}
