#include<iostream>
using namespace std;

int main(){
    string s;
    cout << sizeof(s) << " " << s.length() << " " << s.capacity() << " " << s << endl;
    s = "Hello, World! Welcome to CPP with Linux.";
    cout << sizeof(s) << " " << s.length() << " " << s.capacity() << " " << s << endl;
    s += ". Adding more characters.";
    cout << sizeof(s) << " " << s.length() << " " << s.capacity() << " " << s << endl;
}