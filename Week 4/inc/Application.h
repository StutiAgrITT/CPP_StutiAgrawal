#ifndef APPLICATION_H
#define APPLICATION_H

#include "Choice.h"
#include "Logger.h"
#include "Utility.h"

class Application {
private:
    Logger* _logger;
    Utility* _utility;

    void processChoice(Choice choice);
    void handleAddition();
    void handleMultiplication();

public:
    Application();
    ~Application();
    void run();
};

#endif
