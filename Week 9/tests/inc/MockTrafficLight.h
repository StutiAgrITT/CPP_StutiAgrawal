#ifndef MOCK_TRAFFIC_LIGHT_H
#define MOCK_TRAFFIC_LIGHT_H

#include <gmock/gmock.h>
#include "ITrafficLight.h"

class MockTrafficLight : public ITrafficLight {
public:
    MOCK_METHOD(LightState, getState, (LaneId laneId), (override));
    MOCK_METHOD(void, setState, (LaneId laneId, LightState state), (override));
};

#endif