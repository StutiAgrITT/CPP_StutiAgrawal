#include <iostream>
#include <thread>
#include <mutex>

int balance = 0;
std::mutex m;

void addBalance(int val) {
    for (int i = 0; i < 10000; i++) {
        m.lock();
        balance += val;
        m.unlock();
    }
}

int main() {
    std::thread t1(addBalance, 100);
    std::thread t2(addBalance, 200);
    t1.join();
    t2.join();
    std::cout << balance << '\n';
    return 0;
}