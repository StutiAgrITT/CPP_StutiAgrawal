#ifndef APPLICATION_H
#define APPLICATION_H

#include "Choice.h"

class Application {
private:
    void processChoice(Choice choice);
    void handleAddition();
    void handleMultiplication();

public:
    Application();
    ~Application();
    void run();
};

#endif
