#include <iostream>

class IntPair {
private:
    int m_num1{};
    int m_num2{};

public:
    IntPair(int x = 0, int y = 1)
        : m_num1 { x }
        , m_num2 { y }
    {
        std::cout << "Default constructor invoked.\n";

    }

    IntPair(const IntPair& other) 
        : m_num1 {other.m_num1}
        , m_num2 {other.m_num2}
    {
        std::cout << "Copy constructor invoked.\n";
    }
};

int main() {
    IntPair pair1{};
    IntPair pair2{pair1};
    return 0;
}