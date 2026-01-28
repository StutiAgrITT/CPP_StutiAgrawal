#include <iostream>

int returnByValue() {
    return 10; // just returns a copy
}

const int returnByValueConst() {
    return 10; // returns a const copy
}

int& returnByRef() {
    static int x1 = 30; // must be static to survive after return
    return x1;          // returns reference
}

const int& returnByConstRef() {
    static int x2 = 40; // static so it survives
    return x2;          // returns const reference
}

int* returnByPtr() {
    static int x3 = 50;
    return &x3;         // returns pointer
}

const int* returnByConstPtr() {
    static int x4 = 60;
    return &x4;         // returns pointer to const
}

int main() {
    // 1. Return by value
    int a = returnByValue();
    const int b = returnByValue();
    std::cout << "returnByValue(): a=" << a << ", b=" << b << "\n";
    a = 100;  // allowed
    // b = 200; // not allowed, b is const

    // 2. Return by const value
    int c = returnByValueConst();
    const int d = returnByValueConst();
    std::cout << "returnByValueConst(): c=" << c << ", d=" << d << "\n";
    c = 300;  // allowed
    // d = 400; // not allowed, d is const

    // 3. Return by reference
    int& e = returnByRef();
    const int& f = returnByRef();
    std::cout << "returnByRef(): e=" << e << ", f=" << f << "\n";
    e = 500;      // allowed, modifies original static x
    // f = 600;   // not allowed, f is const

    // 4. Return by const reference
    // int& g = returnByConstRef(); // NOT allowed, cannot bind non-const ref to const ref
    const int& h = returnByConstRef();
    int i = returnByConstRef(); // copy is made
    std::cout << "returnByConstRef(): h=" << h << ", i=" << i << "\n";
    i = 700; // allowed, copy
    // h = 800; // not allowed

    // 5. Return by pointer
    int* j = returnByPtr();
    const int* k = returnByPtr();
    std::cout << "returnByPtr(): *j=" << *j << ", *k=" << *k << "\n";
    *j = 900;      // allowed, modifies original
    // *k = 1000;  // not allowed
    std::cout << "After modifying *j, *j=" << *j << "\n";

    // 6. Return by const pointer
    // int* l = returnByConstPtr(); // NOT allowed, pointer to const cannot bind to non-const
    const int* m = returnByConstPtr();
    int n = *returnByConstPtr(); // copy made
    std::cout << "returnByConstPtr(): *m=" << *m << ", n=" << n << "\n";
    n = 1100; // allowed, copy
    // *m = 1200; // not allowed

    return 0;
}
