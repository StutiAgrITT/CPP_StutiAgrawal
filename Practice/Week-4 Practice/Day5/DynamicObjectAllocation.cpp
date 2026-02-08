#include <iostream>
using namespace std;

class Student {
    int marks;
public:
    Student(int m) : marks(m) {}
    void show() {
        cout << marks << endl;
    }
};

int main() {
    Student* s = new Student(95);
    s->show();
    delete s;
}
