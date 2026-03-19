#include "Utility.h"
#include "Constants.h"
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>

Utility::Utility(ILogger* logger) : _logger(logger) {}

int Utility::getValidInteger() {
    int number;
    while (true) {
        std::cin >> number;
        if (std::cin.fail()) {
            std::cin.clear();
            while (std::cin.get() != Separator::NEWLINE_CHAR);
            _logger->printError(Error::INVALID_INPUT);
            continue;
        }
        if (std::cin.peek() != Separator::NEWLINE_CHAR) {
            while (std::cin.get() != Separator::NEWLINE_CHAR);
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
    int start = input.find_first_not_of(Validation::WHITESPACES);
    if (start == std::string::npos) return "";
    int end = input.find_last_not_of(Validation::WHITESPACES);
    return input.substr(start, end - start + 1);
}

std::string Utility::getValidUsername() {
    std::string username;
    while (true) {
        username = getValidString();
        if (username.empty()) {
            _logger->printError(Error::INVALID_USERNAME);
            continue;
        }
        bool valid = true;
        for (char c : username) {
            if (Validation::INVALID_CHARS.find(c) != std::string::npos) {
                valid = false;
                break;
            }
        }
        if (!valid) {
            _logger->printError(Error::INVALID_INPUT);
            continue;
        }
        return username;
    }
}

std::string Utility::getPassword() {
    std::string password;
    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    char character;
    while (true) {
        character = getchar();
        if (character == Separator::NEWLINE_CHAR) {
            _logger->printMessage(Info::NEWLINE);
            break;
        }
        else if (character == Validation::BACKSPACE_CHAR || character == Validation::DELETE_CHAR) {
            if (!password.empty()) {
                password.pop_back();
                _logger->printMessage(Validation::BACKSPACE_SEQ);
            }
        }
        else {
            password += character;
        }
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return password;
}

std::string Utility::getCurrentDateTime() {
    time_t now = time(0);
    std::string dateTime = std::string(ctime(&now));
    if (!dateTime.empty() && dateTime.back() == Separator::NEWLINE_CHAR)
        dateTime.pop_back();
    return dateTime;
}
