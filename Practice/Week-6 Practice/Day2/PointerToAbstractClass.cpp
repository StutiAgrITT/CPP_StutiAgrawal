#include <iostream>

class Greet {
public:
    virtual void print() = 0;
};

class English : public Greet {
public:
    void print() {
        std::cout << "Hello\n";
    }
};

int main() {
    //Greet* obj = new Greet; -> not allowed
    Greet* obj = new English;
    obj->print();
    return 0;
}
