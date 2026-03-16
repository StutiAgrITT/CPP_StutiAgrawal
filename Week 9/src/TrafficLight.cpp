#include "TrafficLight.h"

TrafficLight::TrafficLight(ILane* lane1, ILane* lane2, ILane* lane3, ILane* lane4) {
    _states[LANE_1] = RED;
    _states[LANE_2] = RED;
    _states[LANE_3] = RED;
    _states[LANE_4] = RED;

    _lanes[LANE_1] = lane1;
    _lanes[LANE_2] = lane2;
    _lanes[LANE_3] = lane3;
    _lanes[LANE_4] = lane4;
}

LightState TrafficLight::getState(LaneId laneId) {
    std::lock_guard<std::mutex> lock(_mutex);
    return _states.at(laneId);
}

void TrafficLight::setState(LaneId laneId, LightState state) {
    {
        std::unique_lock<std::mutex> lock(_mutex);
        _states[laneId] = state;
    }
    if (state == GREEN) {
        _lanes[laneId]->notify();
    }
}
