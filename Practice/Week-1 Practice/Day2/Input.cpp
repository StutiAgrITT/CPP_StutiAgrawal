#include<iostream>
using namespace std;

int main(){
    string cinInput;
    string getlineInput;
    string getlineInput2;

    cin >> cinInput;
    getline(cin, getlineInput);
    getline(cin, getlineInput2);

    cout << cinInput << endl;
    cout << getlineInput << endl;
    cout << getlineInput2 << endl;
}      