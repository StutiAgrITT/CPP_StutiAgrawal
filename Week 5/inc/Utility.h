#ifndef UTILITY_H
#define UTILITY_H

#include "Logger.h"
#include <string>

class Utility {
private:
    Utility();
    static Utility* instance;
    Logger* _logger;

public:
    Utility(const Utility&) = delete;
    Utility& operator=(const Utility&) = delete;

    static Utility* getInstance();

    double getValidDouble();
    double getValidPositiveDouble();
    int getValidInteger();
    std::string getValidString();
    std::string getValidName();
    std::string getValidEmail();
    std::string getValidPhone();
    std::string getPassword();
    std::string getCurrentDateTime();
};

#endif