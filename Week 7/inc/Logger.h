#ifndef LOGGER_H
#define LOGGER_H

#include "ILogger.h"
#include <iostream>

class Logger : public ILogger {
public:
    Logger() = default;
    ~Logger() = default;
    void printError(const std::string& errorMsg) override;
    void printInline(const std::string& message) override;
};

#endif
