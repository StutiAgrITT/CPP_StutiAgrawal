#ifndef UTILITY_H
#define UTILITY_H

#include "IUtility.h"
#include "ILogger.h"

class Utility : public IUtility {
private:
    ILogger* _logger;
public: 
    Utility(ILogger* logger);
    ~Utility() override = default;
    int getValidInteger() override;
    std::string getValidString() override;
    std::string getValidFilename() override;
};

#endif
