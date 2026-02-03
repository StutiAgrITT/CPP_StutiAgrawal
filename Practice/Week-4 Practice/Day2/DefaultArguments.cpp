#include <iostream>

class MyClass
{
private:
    int m_x { };
    int m_y { };

public:
    MyClass(int x=0, int y=0) // has default arguments
        : m_x { x }
        , m_y { y }
    {
        std::cout << "MyClass(" << m_x << ", " << m_y << ") constructed\n";
    }
};

int main()
{
    MyClass foo1{};     // calls MyClass(int, int) constructor using default arguments
    MyClass foo2{6, 7}; // calls MyClass(int, int) constructor

    return 0;
}