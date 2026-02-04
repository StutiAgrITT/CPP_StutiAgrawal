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

IntPair return1() {
    IntPair pair {5, 6};
    return pair;
}
IntPair return2() {
    return IntPair {5, 6};
}
IntPair return3() {
    return {5, 6};
}

void printValue(IntPair pair) {
    std::cout << pair.num1() << " " << pair.num2() << '\n';
}

int main() {
    printValue(return1());
    printValue(return2());
    printValue(return3());
    return 0;
}