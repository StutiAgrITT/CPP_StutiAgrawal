#include <iostream>

void crash(int* ptr) {
    std::cout << *ptr << '\n';
//     Program received signal SIGSEGV, Segmentation fault.
// 0x00005555555551bd in crash (ptr=0x0) at SegmentationFaultFix.cpp:4
// 4           std::cout << *ptr << '\n';
}

int main() {
    //int x = 10;
    int* ptr;
    //ptr = &x;
    crash(ptr);
    return 0;
}