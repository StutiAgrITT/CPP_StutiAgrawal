#include <iostream>
using namespace std;

class Test {
    int* data;
public:
    Test(int v = 0) {
        data = new int(v);
    }

    // Assignment operator
    Test& operator=(const Test& t) {
        if (this == &t) return *this;

        delete data;
        data = new int(*t.data);
        return *this;
    }

    void show() {
        cout << *data << endl;
    }

    ~Test() {
        delete data;
    }
};

int main() {
    Test t1(10), t2;
    t2 = t1;  // assignment
    t2.show();
}
