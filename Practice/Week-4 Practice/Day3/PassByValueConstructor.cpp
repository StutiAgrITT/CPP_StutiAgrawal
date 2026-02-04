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
        : m_num1 {1}
        , m_num2 {2} //to check whether implicit is called or this one
    {
        std::cout << "Copy constructor invoked.\n";
    }
    int num1() { return m_num1; };
    int num2() { return m_num2; };
};

void printValue(IntPair pair) {
    std::cout << pair.num1() << " " << pair.num2() << '\n';
}

int main() {
    IntPair pair1{3, 4};
    IntPair pair2{pair1};
    printValue(pair1); //implicit will not be called
    return 0;
}