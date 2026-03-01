#ifndef UTILITY_H
#define UTILITY_H

#include "IUtility.h"
#include "ILogger.h"

class Utility : public IUtility {
private:
    ILogger* _logger;
    bool isValidPassword(const std::string& password, std::string& errorMsg);
    
public:
    Utility(ILogger* logger);
    ~Utility() = default;
    double getValidDouble() override;
    double getValidPositiveDouble() override;
    int getValidInteger() override;
    std::string getValidString() override;
    std::string getValidName() override;
    std::string getValidEmail() override;
    std::string getValidPhone() override;
    std::string getPassword() override;
    std::string getCurrentDateTime() override;
};

#endif
