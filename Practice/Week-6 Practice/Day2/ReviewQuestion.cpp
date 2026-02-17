#include <iostream>
using namespace std;
 
class A {
public:
    static double y;
    virtual void f() {}
    int x;
};
 
int main()
{
    A a;
    cout << sizeof(a) << endl;
    cout << sizeof(A);
    return 0;
}