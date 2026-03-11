#include <iostream>
#include <thread>

void task() {
    std::cout << "Thread running\n";
}

int main() {
    std::thread t(task);
    t.detach();
    std::cout << "main\n";
    return 0;
}

// output could be:
// main

// or

// main
// Thread running

// or

// Thread running
// main