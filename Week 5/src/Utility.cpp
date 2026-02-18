#include "Utility.h"
#include "Constants.h"
#include <iostream>
#include <termios.h>
#include <unistd.h>

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

double Utility::getValidPositiveDouble() {
    double number;
    while (true) {
        number = getValidDouble();
        if (number <= 0) {
            _logger->printError(Error::INVALID_AMOUNT);
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
            _logger->printError(Error::INVALID_INPUT);
            continue;
        }
        return (int)number;
    }
}

std::string Utility::getValidString() {
    std::string input;
    std::getline(std::cin, input);
    int start = input.find_first_not_of(" \t\n");
    if (start == -1) return "";
    int end = input.find_last_not_of(" \t\n");
    return input.substr(start, end - start + 1);
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
        _logger->printError(Error::INVALID_EMAIL);
        _logger->printInline(Prompt::ENTER_EMAIL);
    }
}

std::string Utility::getValidName() {
    std::string name;

    while (true) {
        name = getValidString();
        if (name.empty()) {
            _logger->printError(Error::INVALID_INPUT);
            _logger->printInline(Prompt::ENTER_NAME);
            continue;
        }

        bool valid = true;
        for (char character : name) {
            if (!isalpha(character) && character != ' ') {
                valid = false;
                break;
            }
        }

        if (!valid) {
            _logger->printError(Error::INVALID_INPUT);
            _logger->printInline(Prompt::ENTER_NAME);
            continue;
        }
        return name;
    }
}

std::string Utility::getValidPhone() {
    std::string phone;
    while (true) {
        phone = getValidString();
        if (phone.empty()) {
            _logger->printError(Error::INVALID_INPUT);
            _logger->printInline(Prompt::ENTER_PHONE);
            continue;
        }
        bool valid = true;
        for (char character : phone) {
            if (!isdigit(character) && (character != '+' && character != '-')) {
                valid = false;
                break;
            }
        }
        if (phone.length() < 10) valid = false;
        if (!valid) {
            _logger->printError(Error::INVALID_PHONE);
            _logger->printInline(Prompt::ENTER_PHONE);
            continue;
        }
        return phone;
    }
}

bool Utility::isValidPassword(const std::string& password, std::string& errorMsg) {
    if (password.length() < Constants::MIN_PASSWORD_LENGTH) {
        errorMsg = Error::PASSWORD_TOO_SHORT;
        return false;
    }

    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;
    std::string specialChars = Constants::SPECIAL_CHARACTERS;

    for (char character : password) {
        if (isupper(character)) hasUpper = true;
        if (islower(character)) hasLower = true;
        if (isdigit(character)) hasDigit = true;
        if (specialChars.find(character) != -1) hasSpecial = true;

        if(hasUpper && hasLower && hasDigit && hasSpecial) break;
    }

    if (!hasUpper) {
        errorMsg = Error::PASSWORD_NO_UPPERCASE;
        return false;
    }
    if (!hasLower) {
        errorMsg = Error::PASSWORD_NO_LOWERCASE;
        return false;
    }
    if (!hasDigit) {
        errorMsg = Error::PASSWORD_NO_DIGIT;
        return false;
    }
    if (!hasSpecial) {
        errorMsg = Error::PASSWORD_NO_SPECIAL;
        return false;
    }
    return true;
}

std::string Utility::getPassword() {
    std::string password;
    std::string errorMsg;
    
    while (true) {
        password = "";
        termios oldt;
        tcgetattr(STDIN_FILENO, &oldt);
        termios newt = oldt;
        newt.c_lflag &= ~ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);

        char character;
        while (true) {
            character = getchar();
            if(character == '\n') {
                _logger->printInline("\n");
                break;
            }
            else if (character == 127 || character == '\b') {
                if (!password.empty()) {
                    password.pop_back();
                    _logger->printInline("\b \b");
                }
            }
            else {
                password += character;
            }
        }

        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

        if(isValidPassword(password, errorMsg)) {
            return password;
        }
        _logger->printError(errorMsg);
        _logger->printInline(Prompt::ENTER_PASSWORD);
    }
}

std::string Utility::getCurrentDateTime() {
    time_t now = time(0);
    char* dateTime = ctime(&now);
    return std::string(dateTime);
}
