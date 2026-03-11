#include <iostream>
#include <thread>
#include <mutex>

int counter = 0;
std::mutex m;

void increment() {
    for (int i = 0; i < 10000; i++) {
        if(m.try_lock())
            counter++;
        m.unlock();
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);
    t1.join();
    t2.join();
    std::cout << counter << '\n';
    return 0;
}

//output random, bcs when one locks, that iteration for other is skipped