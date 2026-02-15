#include "Utility.h"
#include "Constants.h"
#include <iostream>

Utility* Utility::instance = nullptr;

Utility::Utility() {
    _logger = Logger::getInstance();
}

Utility* Utility::getInstance() {
    if (instance == nullptr) {
        instance = new Utility();
    }
    return instance;
}

double Utility::getValidDouble() {
    double number;
    
    while (true) {
        std::cin >> number;
        
        if (std::cin.fail()) {
            std::cin.clear();
            while (std::cin.get() != '\n');
            _logger->printError(_logger->MSG_INVALID_INPUT);
            continue;
        }
        
        if (std::cin.peek() != '\n') {
            while (std::cin.get() != '\n');
            _logger->printError(_logger->MSG_INVALID_INPUT);
            continue;
        }
        return number;
    }
}

double Utility::getValidPositiveDouble() {
    double number;
    while (true) {
        number = getValidDouble();
        if (number <= 0) {
            _logger->printError(_logger->MSG_INVALID_AMOUNT);
            continue;
        }
        return number;
    }
}

int Utility::getValidInteger() {
    double number;
    while (true) {
        number = getValidDouble();
        if (number != (int)number) {
            _logger->printError(_logger->MSG_INVALID_INPUT);
            continue;
        }
        return (int)number;
    }
}

std::string Utility::getValidString() {
    std::string input;
    std::getline(std::cin, input);
    return input;
}

std::string Utility::getValidEmail() {
    std::string email;
    
    while (true) {
        email = getValidString();
        int atPosition = email.find('@');
        int dotPosition = email.find_last_of('.');

        if (atPosition != -1 &&
            atPosition > 0 &&
            atPosition < email.length() - 1 &&
            dotPosition != -1 &&
            dotPosition > atPosition + 1 &&
            dotPosition < email.length() - 1) {
            return email;
        }
        _logger->printError(_logger->MSG_INVALID_EMAIL);
        std::cout << PROMPT_ENTER_EMAIL;
    }
}

std::string Utility::getPassword() {
    std::string password;
    
    while (true) {
        password = getValidString();
        if (password.length() < MIN_PASSWORD_LENGTH) {
            _logger->printError(_logger->MSG_PASSWORD_TOO_SHORT);
            std::cout << PROMPT_ENTER_PASSWORD;
            continue;
        }
        return password;
    }
}

std::string Utility::getCurrentDateTime() {
    time_t now = time(0);
    char* dateTime = ctime(&now);
    return std::string(dateTime);
}
