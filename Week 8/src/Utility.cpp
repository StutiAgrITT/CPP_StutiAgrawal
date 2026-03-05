#include "Utility.h"
#include "Constants.h"
#include <iostream>
#include <string>

Utility::Utility(ILogger* logger) : _logger(logger) {}

int Utility::getValidInteger() {
    int number;
    while (true) {
        std::cin >> number;

        if (std::cin.fail()) {
            std::cin.clear();
            while (std::cin.get() != '\n');
            _logger->printError(Error::INVALID_INPUT);
            continue;
        }
        if (std::cin.peek() != '\n') {
            while (std::cin.get() != '\n');
            _logger->printError(Error::INVALID_INPUT);
            continue;
        }
        std::cin.ignore();
        return number;
    }
}

std::string Utility::getValidString() {
    std::string input;
    std::getline(std::cin, input);

    int start = input.find_first_not_of(" \t\n");
    if (start == std::string::npos) return "";

    int end = input.find_last_not_of(" \t\n");
    return input.substr(start, end - start + 1);
}

std::string Utility::getValidFilename() {
    const std::string invalidChars = "/:*?\"<>|\\";
    std::string filename;

    while (true) {
        filename = getValidString();

        if (filename.empty()) {
            _logger->printError(Error::INVALID_NAME);
            continue;
        }

        bool valid = true;
        for (char c : filename) {
            if (invalidChars.find(c) != std::string::npos) {
                valid = false;
                break;
            }
        }

        if (!valid) {
            _logger->printError(Error::INVALID_INPUT);
            continue;
        }
        return filename;
    }
}
