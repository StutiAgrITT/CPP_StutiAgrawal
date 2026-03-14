#include "Intersection.h"
#include <thread>
#include <iostream>
#include <chrono>

Intersection::Intersection(ILane* lane1, ILane* lane2, ILane* lane3, ILane* lane4, ITrafficLight* light)
    : _lane1(lane1), _lane2(lane2), _lane3(lane3), _lane4(lane4), _light(light), _running(false) {}

Intersection::~Intersection() {
    stop();
}

void Intersection::start() {
    _running = true;
    _controllerThread = std::thread(&Intersection::runController, this);
}

void Intersection::stop() {
    _running = false;
    _lane1->stop();
    _lane2->stop();
    _lane3->stop();
    _lane4->stop();
    if (_controllerThread.joinable()) {
        _controllerThread.join();
    }
}

void Intersection::runPhase(LaneId laneId) {
    _light->setState(laneId, GREEN);
    std::cout << Info::NEWLINE << Info::LIGHT_CHANGE << std::to_string((int)laneId) << Info::COLON << Info::LIGHT_GREEN << Info::NEWLINE;
    std::this_thread::sleep_for(std::chrono::seconds(Timing::GREEN_DURATION));
    if (!_running) return;

    _light->setState(laneId, YELLOW);
    std::cout << Info::NEWLINE << Info::LIGHT_CHANGE << std::to_string((int)laneId) << Info::COLON << Info::LIGHT_YELLOW << Info::NEWLINE;
    std::this_thread::sleep_for(std::chrono::seconds(Timing::YELLOW_DURATION));
    if (!_running) return;

    _light->setState(laneId, RED);
    std::cout << Info::NEWLINE << Info::LIGHT_CHANGE << std::to_string((int)laneId) << Info::COLON << Info::LIGHT_RED << Info::NEWLINE;
}

void Intersection::runController() {
    while (_running) {
        runPhase(LANE_1);
        if (!_running) break;
        runPhase(LANE_2);
        if (!_running) break;
        runPhase(LANE_3);
        if (!_running) break;
        runPhase(LANE_4);
    }
}

ILane* Intersection::getLane(LaneId laneId) {
    switch (laneId) {
        case LANE_1:
            return _lane1;
        case LANE_2: 
            return _lane2;
        case LANE_3:
            return _lane3;
        case LANE_4: 
            return _lane4;
        default:
            return nullptr;
    }
}
