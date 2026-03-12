#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

unsigned long counter = 0;
std::mutex m;

void increment() {
    for (unsigned long i = 0; i < 19000000; i++) {
        std::lock_guard<std::mutex> lock(m);
        counter++;
    }
}

int main() {
    auto startTime = std::chrono::high_resolution_clock::now();
    std::thread t1(increment);
    std::thread t2(increment);
    t1.join();
    t2.join();

    auto stopTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);
    std::cout << counter << '\n';
    std::cout << "Duration: " << duration.count()/1000000 << '\n'; //around 2 sec

    return 0;
}
