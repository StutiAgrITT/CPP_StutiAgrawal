#include <iostream>
#include <thread>
#include <chrono>

void print(int& x) {
    std::cout << x << '\n'; //dangerour - thread using invalid memory
}

int main() {
    int a = 10;
    std::thread t(print, std::ref(a));
    t.detach();
    //std::this_thread::sleep_for(std::chrono::seconds(2)); //removing comment would give correct ans
    return 0;
}