#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    double x = 12.11115; // 12.1112
    float y = 12.11115; // 12.1111
    float z = 12.111155; // 12.1112

    char a = 'ABC'; //implicit conversion from ABC to C

    bool t1 = true; // 1
    bool t2 = -1; // 1
    bool f1 = false; // 0
    bool f2 = 0; // 0

    cout << setprecision(35) << x << endl;
}