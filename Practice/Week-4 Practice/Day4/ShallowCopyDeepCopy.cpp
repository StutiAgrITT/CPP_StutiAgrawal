#include <iostream>
using namespace std;

class Test {
    int* data;
public:
    Test(int val) {
        data = new int(val);
    }

    // Deep copy constructor
    Test(const Test& t) {
        data = new int(*t.data);
    }

    void set(int val) {
        *data = val;
    }

    void show() {
        cout << *data << endl;
    }

    ~Test() {
        delete data;
    }
};

int main() {
    Test t1(10);
    Test t2 = t1;   // deep copy

    t2.set(20);

    t1.show(); // 10
    t2.show(); // 20
}
