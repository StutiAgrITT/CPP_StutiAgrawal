#include<iostream>
using namespace std;

int main(){
    string name;
    bool isValid = true;

    cout << "Enter a variable name: ";
    cin >> name;

    char firstChar = name[0];

    if(!((firstChar >= 'a' && firstChar <= 'z') ||
    (firstChar >= 'A' && firstChar >= 'Z') ||
    firstChar == '_')){
        isValid = false;
    }

    for(int i = 1; i < name.length(); i++){
        char ch = name[i];
        if(!((ch >= 'a' && ch <= 'z') ||
        (ch >= 'A' && ch <= 'Z') ||
        (ch >= '0' && ch <= '9') ||
        ch == '_')){
            isValid = false;
            break;
        }
    }
    if(isValid){
        cout << "Valid variable name" << endl;
    }
    else{
        cout << "Invalid vairable name" << endl;
    }
}