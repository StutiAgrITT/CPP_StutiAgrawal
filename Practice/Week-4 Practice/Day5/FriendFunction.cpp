#include <iostream>
using namespace std;

class Box {
private:
    int width;

public:
    Box(int w) : width(w) {}
    friend void printWidth(Box);
};

void printWidth(Box b) {
    cout << b.width << endl; // private access
}

int main() {
    Box b(50);
    printWidth(b);
}
