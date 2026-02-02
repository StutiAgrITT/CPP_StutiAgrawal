#include <iostream>

struct Bad {
    int m_num = 10;
    int m_good { fcn2() }; // ok bcs fcn2 returning data which was initialized before
    int m_bad1 { m_data }; // undefined behavior: m_bad1 initialized before m_data
    int m_bad2 { fcn1() };  // undefined behavior: m_bad2 initialized before m_data (accessed through fcn())

    int m_data = 5;
    int fcn1() { return m_data; }
    int fcn2() { return m_num; }
};

int main() {
    Bad x;
    std::cout << x.m_good << '\n';
    std::cout << x.m_bad1 << '\n'; //undefined
    std::cout << x.m_bad2 << '\n'; //undefined
    return 0;
}