#include "Logger.h"

void Logger::printError(const std::string& errorMsg) {
    std::cout << "ERROR: " << errorMsg << '\n';
}

void Logger::printInline(const std::string& message) {
    std::cout << message;
}
