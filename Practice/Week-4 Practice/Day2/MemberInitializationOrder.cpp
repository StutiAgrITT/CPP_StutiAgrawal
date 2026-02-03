#include <algorithm> // for std::max
#include <iostream>

class MyClass
{
private:
    int m_x{};
    int m_y{};

public:
    MyClass(int x, int y)
        : m_y { std::max(x, y) }, m_x { m_y } // issue on this line
    {
    }

    void print() const
    {
        std::cout << "MyClass(" << m_x << ", " << m_y << ")\n";
    }
};

int main()
{
    MyClass obj { 6, 7 };
    obj.print();

    return 0;
}