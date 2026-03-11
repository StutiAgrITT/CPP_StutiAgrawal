#include <iostream>
#include <thread>
#include <chrono>

void print(int& x) {
    for (int i = 0; i < x; i++) {
        std::cout << x << '\n';
    }
}

int main() {
    int a = 10;
    std::thread t(print, std::ref(a));
    t.detach();
    std::this_thread::sleep_for(std::chrono::microseconds(2));
    return 0;
}

// diff outputs:

// 1.

// 2.
// 10
// 10
// 10
// 10
// 10
// 10
// 10
// 10
// 10
// 10

// 3.
// 10