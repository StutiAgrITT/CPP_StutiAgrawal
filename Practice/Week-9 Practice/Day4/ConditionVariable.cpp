#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

class Semaphore {
private:
    int count;
    std::mutex mtx;
    std::condition_variable cv;

public:
    Semaphore(int c) : count(c) {}

    void acquire() {
        std::unique_lock<std::mutex> lock(mtx);

        cv.wait(lock, [this]() {
            return count > 0;
        });

        count--;
    }

    void release() {
        std::unique_lock<std::mutex> lock(mtx);

        count++;

        lock.unlock();       // unlock before notify
        cv.notify_one();
    }
};

Semaphore sem(2);

void worker(int id) {
    sem.acquire();

    std::cout << "Thread " << id << " entered\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Thread " << id << " leaving\n";

    sem.release();
}

int main() {
    std::thread t1(worker,1);
    std::thread t2(worker,2);
    std::thread t3(worker,3);

    t1.join();
    t2.join();
    t3.join();
}