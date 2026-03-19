#ifndef PROFILE_MANAGER_H
#define PROFILE_MANAGER_H

#include "ILogger.h"
#include "Profile.h"
#include <string>

class ProfileManager {
private:
    ILogger* _logger;
    std::string buildProfilePath(const std::string& username) const;
public:
    ProfileManager(ILogger* logger);
    ~ProfileManager() = default;
    Profile loadProfile(const std::string& username);
    void saveProfile(const Profile& profile);
    void incrementPostCount(const std::string& username);
};

#endif