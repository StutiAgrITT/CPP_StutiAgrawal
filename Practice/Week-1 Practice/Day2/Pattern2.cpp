//          1
//        1 0
//      1 0 1
//    1 0 1 0
//  1 0 1 0 1
//    1 0 1 0
//      1 0 1
//        1 0
//          1

#include<iostream>

using namespace std;

int main(){
    int n;
    cout << "Enter number of columns: ";
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int s = 1; s <= (n - i); s++) cout << "  ";
        for(int j = 1; j <= i; j++){
            if(j & 1) cout << "1 ";
            else cout << "0 ";
        }
        cout << endl;
    }
    for(int i = n - 1; i >= 1; i--){
        for(int s = 1; s <= n - i; s++) cout << "  ";
        for(int j = 1; j <= i; j++){
            if(j % 2 == 1) cout << "1 ";
            else cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}