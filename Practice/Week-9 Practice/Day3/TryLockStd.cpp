#include <iostream>
#include <mutex>

std::mutex m1, m2;

int main() {
    int result = std::try_lock(m1, m2);

    if (result == -1) {
        std::cout << "Both mutexes locked successfully\n";

        m1.unlock();
        m2.unlock();
    } else {
        std::cout << "Failed to lock mutex at index: " << result << "\n";
    }
}
