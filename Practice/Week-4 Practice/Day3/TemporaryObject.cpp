#include <iostream>

class IntPair {
private:
    int m_num1{};
    int m_num2{};

public:
    IntPair(int x, int y) 
        : m_num1 { x }
        , m_num2 { y } 
    {
    }
    int num1() { return m_num1; }
    int num2() { return m_num2; }
};

void printValue(IntPair pair) {
    std::cout << pair.num1() << " " << pair.num2() << '\n';
}

int main() {
    // create an object : unnecessary
    IntPair pair1 = {6, 7};
    printValue(pair1);
    // temporary object
    printValue(IntPair {6, 7});
    // compiler implicitly creates temporary object
    printValue({6, 7});
    //if no constructor was matching with the arguments, then compiler error
    return 0;
}