#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>

class Logger {
private:
    Logger();
    static Logger* instance;

public:
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    
    static Logger* getInstance();

    void printError(const std::string& errorMsg);
    void printMessage(const std::string& message);
};

#endif