#include <algorithm> // for std::max
#include <iostream>

class MyClass
{
private:
    int m_x{1};
    int m_y{1};
    int m_z;

public:
    MyClass(int x)
        : m_x {2} // this is preferred
    {
    }

    void print() const
    {
        std::cout << "MyClass(" << m_x << ", " << m_y << ", " << m_z << ")\n";
    }
};

int main()
{
    MyClass obj { 6 };
    obj.print();

    return 0;
}