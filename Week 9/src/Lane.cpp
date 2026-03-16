#include "Lane.h"

Lane::Lane(LaneId laneId)
    : _laneId(laneId), _semaphore(Config::MAX_CARS), _light(nullptr), _stopped(false) {}

void Lane::enter() {
    std::unique_lock<std::mutex> lock(_mutex);
    _conditionVariable.wait(lock, [this] {
        return _stopped || _light->getState(_laneId) == GREEN;
    });
    if (_stopped) return;
    lock.unlock();
    _semaphore.acquire();
}

void Lane::stop() {
    _stopped = true;
    _conditionVariable.notify_all();
}

void Lane::setLight(ITrafficLight* light) {
    _light = light;
}

void Lane::release() {
    _semaphore.release();
}

LaneId Lane::getLaneId() const {
    return _laneId;
}

void Lane::notify() {
    _conditionVariable.notify_all();
}
