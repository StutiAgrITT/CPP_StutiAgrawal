#ifndef ILOGGER_H
#define ILOGGER_H
#include <string>

class ILogger {
public:
    virtual ~ILogger() = default;
    virtual void printError(const std::string& errorMsg) = 0;
    virtual void printInline(const std::string& message) = 0;
};

#endif
