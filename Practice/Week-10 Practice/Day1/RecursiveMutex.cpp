#include <iostream>
#include <thread>
#include <mutex>

std::recursive_mutex m; // without recursive, deadlock will be caused.
int buffer = 0;

void recursion(char c, int loopFor) {
    if (loopFor < 0) {
        return;
    }
    m.lock();
    std::cout << c << " " << buffer++ << '\n';
    recursion(c, --loopFor); //m is still locked. if normal mutex then deadlock, with recursive we can lock again.
    m.unlock();
    std::cout << "unlocked by thread " << c << '\n';
}

int main() {
    std::thread t1(recursion, '0', 10);
    std::thread t2(recursion, '1', 10);
    t1.join();
    t2.join();
    return 0;
}
