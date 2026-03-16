#ifndef LANE_H
#define LANE_H

#include "ILane.h"
#include "ITrafficLight.h"
#include "Semaphore.h"
#include "Enums.h"
#include "Constants.h"
#include <mutex>
#include <condition_variable>

class Lane : public ILane {
private:
    LaneId _laneId;
    Semaphore _semaphore;
    ITrafficLight* _light;
    std::mutex _mutex;
    std::condition_variable _conditionVariable;
    bool _stopped;
public:
    Lane(LaneId laneId);
    ~Lane() override = default;
    void enter() override;
    void setLight(ITrafficLight* light) override;
    void release() override;
    LaneId getLaneId() const override;
    void notify() override;
    void stop() override;
};

#endif
