#include <iostream>

void changeValue(const int& changeMe) { //if const remves, will give error (cant bind to rvalue)
    //changeMe = 99; error
}

int main() {
    const int& ref = 10; //10 is stored in temp, then referred to temp
    changeValue(10);

    int x = 10;
    const int& ref2 = x;
    x++;
    std::cout << ref2 << '\n'; //bound to x

    short y = 1;
    const int& ref3 = y; // bound to temp converted value
    y++;
    std::cout << ref3 << '\n';
    
    return 0;
}