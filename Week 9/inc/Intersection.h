#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "ILane.h"
#include "ITrafficLight.h"
#include "Enums.h"
#include "Constants.h"
#include <thread>

class Intersection {
private:
    ILane* _lane1;
    ILane* _lane2;
    ILane* _lane3;
    ILane* _lane4;
    ITrafficLight* _light;
    std::thread _controllerThread;
    bool _running;
    void runController();
    void runPhase(LaneId laneId);
public:
    Intersection(ILane* lane1, ILane* lane2, ILane* lane3, ILane* lane4, ITrafficLight* light);
    ~Intersection();
    void start();
    void stop();
    ILane* getLane(LaneId laneId);
};

#endif
