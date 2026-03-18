#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> counter;
int times = 100000;

void run() {
    for (int i = 0; i < times; i++) {
        counter++;
    }
}

int main() {
    std::thread t1(run);
    std::thread t2(run);

    t1.join();
    t2.join();

    std::cout << counter << '\n';
    return 0;
}