#include <iostream>

class MyClass
{
private:
    int m_x {};
    int m_y {};

public:
    MyClass() // default constructor
    {
        std::cout << "MyClass constructed\n";
    }

    MyClass(int x, int y) // non-default constructor
        : m_x { x }, m_y { y }
    {
        std::cout << "MyClass(" << m_x << ", " << m_y << ") constructed\n";
    }
    MyClass(int x = 0, int y = 0)
    {
        //ambigious
    }
};

int main()
{
    MyClass obj1{};     // Calls MyClass() constructor
    MyClass obj2{6, 7}; // Calls MyClass(int, int) constructor

    return 0;
}