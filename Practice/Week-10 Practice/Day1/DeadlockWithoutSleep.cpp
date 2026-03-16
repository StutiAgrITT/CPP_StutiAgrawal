#include <iostream>
#include <mutex>
#include <thread>

std::mutex m1, m2;

void task1() {
    while (true) {
        m1.lock();
        m2.lock();
        std::cout << "task 1\n";
        m1.unlock();
        m2.unlock();
    }
}
void task2() {
    while (true) {
        m2.lock();
        m1.lock();
        std::cout << "task 2\n";
        m1.unlock();
        m2.unlock();
    }
}

int main() {
    std::thread t1(task1);
    std::thread t2(task2);
    t1.join();
    t2.join();
    return 0;
}