#include "Semaphore.h"

Semaphore::Semaphore(int count) : _count(count) {}

void Semaphore::acquire() {
    std::unique_lock<std::mutex> lock(_mutex);
    _conditionVariable.wait(lock, [this] { return _count > 0; });
    _count--;
}

void Semaphore::release() {
    std::unique_lock<std::mutex> lock(_mutex);
    _count++;
    _conditionVariable.notify_one();
}

int Semaphore::getCount() {
    std::unique_lock<std::mutex> lock(_mutex);
    return _count;
}
