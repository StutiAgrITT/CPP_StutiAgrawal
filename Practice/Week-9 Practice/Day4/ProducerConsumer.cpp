#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

std::queue<int> buffer;
const int MAX_SIZE = 5;

std::mutex mtx;
std::condition_variable cv;

void producer() {
    for(int i = 1; i <= 10; i++) {

        std::unique_lock<std::mutex> lock(mtx);

        cv.wait(lock, []{
            return buffer.size() < MAX_SIZE;
        });

        buffer.push(i);
        std::cout << "Produced: " << i << '\n';

        lock.unlock();
        cv.notify_all();
    }
}

void consumer() {

    for(int i = 1; i <= 10; i++) {

        std::unique_lock<std::mutex> lock(mtx);

        cv.wait(lock, []{
            return !buffer.empty();
        });

        int item = buffer.front();
        buffer.pop();

        std::cout << "Consumed: " << item << std::endl;

        lock.unlock();
        cv.notify_all();
    }
}

int main() {
    std::thread p(producer);
    std::thread c(consumer);

    p.join();
    c.join();
    return 0;
}