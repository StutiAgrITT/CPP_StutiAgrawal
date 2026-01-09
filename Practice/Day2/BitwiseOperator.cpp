#include<iostream>

using namespace std;

void oddEven(int n){
    if(n & 1){
        cout << "Odd number" << endl;
    }
    else{
        cout << "Even number" << endl;
    }
}

void isPowerOfTwo(int n){
    if(n > 0 && (n & (n - 1))){
        cout << "Not a power of 2" << endl;
    }
    else{
        cout << "Is a power of 2" << endl;
    }
}

int countSetBits(int n){
    int count = 0;
    int temp = n;
    while(temp){
        if(temp & 1) count++;
        temp = temp >> 1;
    }
    return count;
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;

    oddEven(n);
    isPowerOfTwo(n);
    int setBitsCount = countSetBits(n);
    cout << "Number of set bits: " << setBitsCount << endl;
}
