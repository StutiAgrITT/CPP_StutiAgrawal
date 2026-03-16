#include <iostream>
#include <thread>
#include <mutex>

std::mutex m1;
std::mutex m2;

void work() {
    if (std::try_lock(m1, m2) == -1) {
        std::cout << "Both locks acquired\n";
        m1.unlock();
        m2.unlock();
    }
    else {
        std::cout << "Could not acquire locks\n";
    }
}

int main() {
    std::thread t1(work);
    std::thread t2(work);
    t1.join();
    t2.join();
    return 0;
}