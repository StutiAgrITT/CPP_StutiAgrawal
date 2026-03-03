#ifndef IUTILITY_H
#define IUTILITY_H
#include <string>

class IUtility {
public:
    virtual ~IUtility() = default;
    virtual double getValidDouble() = 0;
    virtual double getValidPositiveDouble() = 0;
    virtual int getValidInteger() = 0;
    virtual std::string getValidString() = 0;
    virtual std::string getValidName() = 0;
    virtual std::string getValidEmail() = 0;
    virtual std::string getValidPhone() = 0;
    virtual std::string getPassword() = 0;
    virtual std::string getCurrentDateTime() = 0;
};

#endif
