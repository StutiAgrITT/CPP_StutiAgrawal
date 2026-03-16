#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

#include "ITrafficLight.h"
#include "ILane.h"
#include "Enums.h"
#include <map>
#include <mutex>

class TrafficLight : public ITrafficLight {
private:
    std::map<LaneId, LightState> _states;
    std::map<LaneId, ILane*> _lanes;
    std::mutex _mutex;
public:
    TrafficLight(ILane* lane1, ILane* lane2, ILane* lane3, ILane* lane4);
    ~TrafficLight() override = default;
    LightState getState(LaneId laneId) override;
    void setState(LaneId laneId, LightState state) override;
};

#endif
