#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <chrono>

class CountingSemaphore {
private:
    int count;
    std::mutex mtx;
    std::condition_variable cv;

public:
    CountingSemaphore(int initial_count) {
        count = initial_count;
    }

    void acquire() {
        std::unique_lock<std::mutex> lock(mtx);

        // Wait until count > 0
        cv.wait(lock, [this]() {
            return count > 0;
        });

        count--;
    }

    void release() {
        std::unique_lock<std::mutex> lock(mtx);

        count++;

        lock.unlock();      // unlock before notifying
        cv.notify_one();    // wake one waiting thread
    }
};

CountingSemaphore sem(2);

void worker(int id) {
    sem.acquire();

    std::cout << "Thread " << id << " entered critical section\n";

    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "Thread " << id << " leaving critical section\n";

    sem.release();
}

int main() {

    std::vector<std::thread> threads;

    for(int i = 1; i <= 5; i++) {
        threads.emplace_back(worker, i);
    }

    for(auto &t : threads) {
        t.join();
    }

    return 0;
}