#include <iostream>

class MyClass {
private:
    int m_id;
    std::string m_name;

public:
    MyClass(int id, std::string name) {
        std::cout << "Object created, Constructor called\n";
        m_id = id;
        m_name = name;
    }
};

int main() {
    MyClass obj {814, "Stuti"};
    return 0;
}