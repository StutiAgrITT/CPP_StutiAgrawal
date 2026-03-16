#ifndef ITRAFFIC_LIGHT_H
#define ITRAFFIC_LIGHT_H

#include "Enums.h"

class ITrafficLight {
public:
    virtual ~ITrafficLight() = default;
    virtual LightState getState(LaneId laneId) = 0;
    virtual void setState(LaneId laneId, LightState state) = 0;
};

#endif
