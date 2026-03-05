#include "Logger.h"

void Logger::printMessage(const std::string& message) {
    std::cout << message;
}

void Logger::printError(const std::string& error) {
    std::cout << "ERROR: " << error;
}
