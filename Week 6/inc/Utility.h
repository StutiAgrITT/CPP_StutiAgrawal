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

    int getValidInteger();
    int getValidAge();
    std::string getValidString();
    std::string getValidFilename();
    char getValidGender();
};

#endif
