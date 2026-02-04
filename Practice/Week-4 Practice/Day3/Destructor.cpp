#include <iostream>

class Simple {
private:
    int m_id;
public:
    Simple(int x = 0)
        : m_id { x }
    {
        std::cout << "Constructing: " << m_id << '\n';
    }
    ~Simple()
    {
        std::cout << "Destructing: " << m_id << '\n';
    }
};

int main() {
    Simple obj1 { 1 };
    {
        Simple obj2 { 2 };
    }
    exit(0); // destructor 2 will not be called as exit does not destructors
    return 0;
}