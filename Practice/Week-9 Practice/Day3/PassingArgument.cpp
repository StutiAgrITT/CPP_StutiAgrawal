#include <iostream>
#include <thread>

void task(int x) {
    std::cout << "Thread running\n" << x << '\n';
}

int main() {
    std::thread t(task, 5);
    t.join();
    return 0;
}