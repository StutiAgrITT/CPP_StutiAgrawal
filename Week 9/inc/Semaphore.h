#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <mutex>
#include <condition_variable>

class Semaphore {
private:
    int _count;
    std::mutex _mutex;
    std::condition_variable _conditionVariable;
public:
    Semaphore(int count);
    ~Semaphore() = default;
    void acquire();
    void release();
    int getCount();
};

#endif
