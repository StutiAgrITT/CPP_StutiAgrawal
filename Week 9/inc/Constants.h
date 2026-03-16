#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

namespace Timing {
    const int GREEN_DURATION  = 5;
    const int YELLOW_DURATION = 2;
    const int CAR_SPAWN_INTERVAL = 1;
    const int SIMULATION_DURATION = 30;
    const int CAR_CROSS_DURATION = 2;
}

namespace Config {
    const int MAX_CARS = 3;
    const int TOTAL_LANES = 4;
}

namespace Info {
    const std::string LIGHT_TAG = "[LIGHT] ";
    const std::string CAR_TAG = "[CAR ";
    const std::string SEPARATOR = "=== Traffic Light Simulation ===";
    const std::string SIM_END = "=== Simulation Complete ===";
    const std::string ARRIVING = "Arriving at Lane ";
    const std::string ENTERING = "Entering intersection from Lane ";
    const std::string CLEARING = "Clearing intersection from Lane ";
    const std::string DONE = "Done";
    const std::string NEWLINE = "\n";
    const std::string END_SQUARE_BRACKET = "] ";
    const std::string LIGHT_GREEN = "GREEN";
    const std::string LIGHT_YELLOW = "YELLOW";
    const std::string LIGHT_RED = "RED";
    const std::string LIGHT_CHANGE = "[LIGHT] Lane ";
    const std::string TICK = "\n--- t=";
    const std::string TICK_END = "s ---\n";
    const std::string COLON = ": ";
}

#endif
