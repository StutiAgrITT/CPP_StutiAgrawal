#ifndef IUTILITY_H
#define IUTILITY_H

#include <string>

class IUtility {
public:
    virtual ~IUtility() = default;
    virtual int getValidInteger() = 0;
    virtual std::string getValidString() = 0;
    virtual std::string getValidUsername() = 0;
    virtual std::string getPassword() = 0;
    virtual std::string getCurrentDateTime() = 0;
};

#endif
