#include <iostream>

class C2;

class C1 {
    int _value;
public:
    void setValue(int value) {
        _value = value;
    }
    int value() {
        return _value;
    }
    friend void swap(C1&, C2&);
};

class C2 {
    int _value;
public:
    void setValue(int value) {
        _value = value;
    }
    int value() {
        return _value;
    }
    friend void swap(C1&, C2&);
};

void swap(C1& a, C2& b) {
    int temp = a._value;
    a._value = b._value;
    b._value = temp;
};

int main() {
    C1 a;
    C2 b;
    a.setValue(5);
    b.setValue(6);
    std::cout << a.value() << " " << b.value() << '\n';
    swap(a, b);
    std::cout << a.value() << " " << b.value() << '\n';
    return 0;   
}

