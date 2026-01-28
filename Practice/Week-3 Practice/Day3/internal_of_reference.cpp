#include <iostream>

void passByRef(int& x) {

}

void passByAdd(int* x) {

}

//both functions have same assembly code
//seen in compiler explorer

int main() {
    int x;
    int* ptr = &x;
    int& ref = x;
    return 0;
}