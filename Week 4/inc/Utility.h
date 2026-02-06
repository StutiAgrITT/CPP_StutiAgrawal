#ifndef UTILITY_H
#define UTILITY_H

#include "Logger.h"

class Utility {
private:
    Utility();
    static Utility* instance;

    Logger* _logger;

public:
    Utility(const Utility&) = delete;
    Utility& operator=(const Utility&) = delete;
    static Utility* getInstance();

    double getValidDouble();
    int getValidPositiveInteger();
    void showMenu();
};

#endif
