#include <iostream>

void function() {
    int* ptr = new int;
    //function ends, ptr goes out of scope, memory leak
}

int main() {
    int* ptr = new int;
    int x = 5;
    ptr = &x; //ptr pointing to something else, memory leaked
    //use delete to free memory
}