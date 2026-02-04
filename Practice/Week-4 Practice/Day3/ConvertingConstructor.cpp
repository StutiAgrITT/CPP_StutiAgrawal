#include <iostream>

class IntPair {
private:
    int m_num1;

public:
    IntPair(int x) //if put explicit, then line in main would give error
        : m_num1 { x }
    {
    }
    int num1() { return m_num1; }
};

void printValue(IntPair pair) {
    std::cout << pair.num1() << '\n';
}

int main() {
    printValue(3);
    return 0;
}