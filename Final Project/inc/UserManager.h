#ifndef USER_MANAGER_H
#define USER_MANAGER_H

#include "ILogger.h"
#include "Validator.h"
#include "User.h"
#include <string>

class UserManager {
private:
    Validator* _validator;
    ILogger* _logger;
    std::string buildUserPath(const std::string& username) const;
    std::string buildProfilePath(const std::string& username) const;
public: 
    UserManager(Validator* validator, ILogger* logger);
    ~UserManager() = default;
    bool signUp(const std::string& username, const std::string& password, 
                const std::string& displayName, const std::string& bio);
    bool signIn(const std::string& username, const std::string& password);
    bool userExists(const std::string& username) const;
};

#endif
