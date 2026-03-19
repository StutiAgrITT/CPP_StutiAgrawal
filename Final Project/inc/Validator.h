#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "ILogger.h"
#include <string>

class Validator {
private:
    ILogger* _logger;
public:
    Validator(ILogger* logger);
    ~Validator() = default;
    bool validatePassword(const std::string& password);
    bool validateUsername(const std::string& username);
};

#endif
