#ifndef SIMULATION_H
#define SIMULATION_H

#include "Intersection.h"
#include "ILane.h"
#include <vector>
#include <thread>
#include <mutex>

class Simulation {
private:
    Intersection* _intersection;
    std::vector<std::thread> _carThreads;
    std::mutex _printMutex;
    bool _running;
    void carLogic(LaneId laneId, int carId);
    void print(const std::string& message);
public:
    Simulation(Intersection* intersection);
    ~Simulation();
    void run();
    void stop();
};

#endif
