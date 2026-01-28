#include <iostream>

int& function() {
    int n = 10;
    return n; //will not exist after function ends
}

int main() {
    int& i = function();
    std::cout << i << '\n'; //segmentation fault (dangling reference)
    return 0;
}