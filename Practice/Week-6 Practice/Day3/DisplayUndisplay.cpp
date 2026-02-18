#include <iostream>

void function(int j) { //when this line is showed in gdb, it may not be properly stacked, hence garbage value is showed
    j -= 30;
    j /= 3;
}

int main() {
    int j;
    j = 10;
    j *= 3;
    j += 36;
    function(j);
    return 0;
}