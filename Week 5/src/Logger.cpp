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
    std::cout << message << '\n';
}

void Logger::printError(const std::string& errorMsg) {
    std::cout << "ERROR: " << errorMsg << '\n';
}

void Logger::printInline(const std::string& message) {
    std::cout << message << ' ';
}
