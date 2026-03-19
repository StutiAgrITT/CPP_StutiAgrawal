#include "Validator.h"
#include "Constants.h"

Validator::Validator(ILogger* logger) : _logger(logger) {}

bool Validator::validatePassword(const std::string& password) {
    if (password.length() < Validation::MIN_PASSWORD_LEN) {
        _logger->printError(Error::INVALID_PASSWORD);
        return false;
    }
    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;
    for (char c : password) {
        if (std::isupper(c)) hasUpper = true;
        else if (std::islower(c)) hasLower = true;
        else if (std::isdigit(c)) hasDigit = true;
        else hasSpecial = true;
    }
    if (!hasUpper || !hasLower || !hasDigit || !hasSpecial) {
        _logger->printError(Error::INVALID_PASSWORD);
        return false;
    }
    return true;
}

bool Validator::validateUsername(const std::string& username) {
    if (username.empty()) {
        _logger->printError(Error::INVALID_USERNAME);
        return false;
    }
    for (char c : username) {
        if (Validation::INVALID_CHARS.find(c) != std::string::npos) {
            _logger->printError(Error::INVALID_USERNAME);
            return false;
        }
    }
    return true;
}
