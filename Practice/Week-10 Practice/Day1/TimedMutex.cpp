#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

int amount = 0;
std::timed_mutex m;

void increment(int i) {
    auto now = std::chrono::steady_clock::now();
    if (m.try_lock_for(std::chrono::seconds(3))) { // waits for 3 seconds
        ++amount;
        std::this_thread::sleep_for(std::chrono::seconds(2)); // finishes in 2 sec
        std::cout << "thread " << i << " entered" << '\n';
        m.unlock();
    }
    else {
        std::cout << "thread " << i << " couldnt enter" << '\n';
    }
}

int main() {
    std::thread t1(increment, 1);
    std::thread t2(increment, 2);

    t1.join();
    t2.join();

    std::cout << amount << '\n';
    return 0;
}