#include <iostream>
#include <thread>

void loop1() {
    for (int i = 1; i <= 10; i++) {
        std::cout << i << '\n';
    }
}

void loop2() {
    for (int i = 11; i <= 20; i++) {
        std::cout << i << '\n';
    }
}

int main() {
    std::thread t1(loop1);
    std::thread t2(loop2);
    //doesnt guarentee which thread will start first
    t1.join();
    t2.join();
    return 0;
}

// outputs:
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9
// 10
// 11
// 12
// 13
// 14
// 15
// 16
// 17
// 18
// 19
// 20

// 2nd output
// 11
// 1
// 2
// 3
// 4
// 5
// 12
// 13
// 14
// 15
// 16
// 17
// 18
// 19
// 20
// 6
// 7
// 8
// 9
// 10