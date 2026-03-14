#ifndef ILANE_H
#define ILANE_H

#include "Enums.h"
#include "ITrafficLight.h"

class ILane {
public:
    virtual ~ILane() = default;
    virtual void setLight(ITrafficLight* light) = 0;
    virtual void enter() = 0;
    virtual void release() = 0;
    virtual LaneId getLaneId() const = 0;
    virtual void notify() = 0;
    virtual void stop() = 0;
};

#endif
