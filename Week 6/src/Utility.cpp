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

int Utility::getValidInteger() {
    int number;
    
    while (true) {
        std::cin >> number;
        
        if (std::cin.fail()) {
            std::cin.clear();
            while (std::cin.get() != '\n');
            _logger->printMessage(Error::INVALID_INPUT);
            continue;
        }
        
        if (std::cin.peek() != '\n') {
            while (std::cin.get() != '\n');
            _logger->printMessage(Error::INVALID_INPUT);
            continue;
        }
        std::cin.ignore();
        return number;
    }
}

int Utility::getValidAge() {
    int age;
    while (true) {
        age = getValidInteger();
        if (age <= Constants::MIN_AGE || age >= Constants::MAX_AGE) {
            _logger->printError(Error::INVALID_AGE);
            _logger->printMessage(Prompt::ENTER_AGE);
        }
        return age;
    }
}

std::string Utility::getValidString() {
    std::string input;
    std::getline(std::cin, input);
    
    int start = input.find_first_not_of(Constants::WHITESPACES);
    if (start == -1) {
        return Constants::EMPTY;
    }
    
    int end = input.find_last_not_of(Constants::WHITESPACES);
    return input.substr(start, end - start + 1);
}

std::string Utility::getValidFilename() {
    std::string filename;
    
    while (true) {
        filename = getValidString();
        
        if (filename.empty()) {
            _logger->printMessage(Error::INVALID_CHOICE);
            _logger->printMessage(Prompt::ENTER_FILENAME);
            continue;
        }
        
        bool valid = true;
        for (char character : filename) {
            if (Constants::INVALID_FILENAME_CHARS.find(character) != -1) {
                valid = false;
                break;
            }
        }
        
        if (!valid) {
            _logger->printMessage(Error::INVALID_CHOICE);
            _logger->printMessage(Prompt::ENTER_FILENAME);
            continue;
        }
        return filename;
    }
}

char Utility::getValidGender() {
    char gender;

    while (true) {
        std::cin >> gender;

        if (std::cin.fail()) {
            std::cin.clear();
            while (std::cin.get() != '\n');
            _logger->printMessage(Error::INVALID_GENDER);
            _logger->printMessage(Prompt::ENTER_GENDER);
            continue;
        }
        
        if (std::cin.peek() != '\n') {
            while (std::cin.get() != '\n');
            _logger->printMessage(Error::INVALID_GENDER);
            _logger->printMessage(Prompt::ENTER_GENDER);
            continue;
        }
        std::cin.ignore();
        return gender;
    }
}
