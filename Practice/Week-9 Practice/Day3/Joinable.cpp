#include <iostream>
#include <chrono>
#include <thread>

void run(int count) {
    while (count-- > 0) {
        std::cout << "hi\n";
    }
    std::this_thread::sleep_for(std::chrono::seconds(3));
}

int main() {
    std::thread t1(run, 5);
    std::cout << "main()\n"; // can be before, between, after the hi's
    t1.join();
    // lots of code
    if (t1.joinable()) t1.join(); // now wont crash
    std::cout << "main() after\n"; // wont crash now, will run
    return 0;
}
