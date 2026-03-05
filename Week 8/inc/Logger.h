#ifndef LOGGER_H
#define LOGGER_H

#include "ILogger.h"
#include <iostream>

class Logger : public ILogger {
public:
    Logger() = default;
    ~Logger() = default;
    void printMessage(const std::string& message) override;
    void printError(const std::string& error) override;
};

#endif
