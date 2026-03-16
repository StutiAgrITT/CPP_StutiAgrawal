#include "Simulation.h"
#include "Constants.h"
#include <chrono>
#include <iostream>
#include <string>

Simulation::Simulation(Intersection* intersection)
    : _intersection(intersection), _running(false), _stopped(false) {}

Simulation::~Simulation() {
    stop();
}

void Simulation::print(const std::string& message) {
    std::lock_guard<std::mutex> lock(_printMutex);
    std::cout << message << Info::NEWLINE;
}

void Simulation::carLogic(LaneId laneId, int carId) {
    std::string carStr = Info::CAR_TAG + std::to_string(carId) + Info::END_SQUARE_BRACKET;

    print(carStr + Info::ARRIVING  + std::to_string((int)laneId));
    
    ILane* lane = _intersection->getLane(laneId);
    lane->enter();

    if (!_running) {
        lane->release();
        return;
    }

    print(carStr + Info::ENTERING + std::to_string((int)laneId));
    std::this_thread::sleep_for(std::chrono::seconds(Timing::CAR_CROSS_DURATION));
    print(carStr + Info::CLEARING + std::to_string((int)laneId));
    lane->release();
    print(carStr + Info::DONE);
}

void Simulation::run() {
    _running = true;
    _intersection->start();

    print(Info::SEPARATOR);

    int carId = 1;
    LaneId lanes[] = { LANE_1, LANE_2, LANE_3, LANE_4 };

    auto startTime = std::chrono::steady_clock::now();

    while (_running) {
        auto elapsed = std::chrono::steady_clock::now() - startTime;
        if (std::chrono::duration_cast<std::chrono::seconds>(elapsed).count() >= Timing::SIMULATION_DURATION) {
            break;
        }

        for (LaneId laneId : lanes) {
            _carThreads.emplace_back(&Simulation::carLogic, this, laneId, carId++);
        }

        std::this_thread::sleep_for(std::chrono::seconds(Timing::CAR_SPAWN_INTERVAL));
    }
    
    stop();

    for (std::thread& carThread : _carThreads) {
        if (carThread.joinable()) carThread.join();
    }

    print(Info::SIM_END);
}

void Simulation::stop() {
    if (_stopped) return;
    _stopped = true;
    _running = false;
    _intersection->stop();
}
