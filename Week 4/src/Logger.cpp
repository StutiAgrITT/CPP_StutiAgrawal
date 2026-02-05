#include "Logger.h"

Logger* Logger::instance = nullptr;

Logger::Logger() = default;

Logger* Logger::getInstance() {
    if (instance == nullptr) {
        instance = new Logger();
    }
    return instance;
}

void Logger::printMessage(const std::string& message) {
    std::cout << message << std::endl;
}

void Logger::printMessage(const std::string& message, int row, int column) {
    std::cout << message << "(" << row << ", " << column << ") : ";
}
