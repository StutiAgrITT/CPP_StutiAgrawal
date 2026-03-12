#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

class BinarySemaphore {

private:
    bool signal = true;
    std::mutex mtx;
    std::condition_variable cv;

public:

    void acquire() {
        std::unique_lock<std::mutex> lock(mtx);

        cv.wait(lock, [this] {
            return signal == true;
        });

        signal = false;
    }

    void release() {
        std::unique_lock<std::mutex> lock(mtx);

        signal = true;

        lock.unlock();
        cv.notify_one();
    }
};

BinarySemaphore sem;

void task(int id) {

    sem.acquire();
    std::cout << "Thread " << id << " inside critical section\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    sem.release();
}

int main() {

    std::thread t1(task,1);
    std::thread t2(task,2);
    std::thread t3(task,3);

    t1.join();
    t2.join();
    t3.join();
}