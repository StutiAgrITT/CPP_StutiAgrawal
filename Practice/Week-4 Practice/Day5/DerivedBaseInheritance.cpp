#include <iostream>
using namespace std;

class Base {
private:
    int a = 10;

protected:
    int b = 20;

public:
    int c = 30;
};

class DerivedProtected : protected Base {
public:
    void show() {
        // a not accessible
        cout << b << " " << c << endl; // protected now
    }
};

class DerivedPrivate : private Base {
public:
    void show() {
        cout << b << " " << c << endl; // private now
    }
};

int main() {
    DerivedProtected dp;
    dp.show();

    DerivedPrivate dpr;
    dpr.show();
}
