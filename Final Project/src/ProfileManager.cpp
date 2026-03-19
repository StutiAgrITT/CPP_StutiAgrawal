#include "ProfileManager.h"
#include "Constants.h"
#include "Exceptions.h"
#include <fstream>
#include <string>

ProfileManager::ProfileManager(ILogger* logger) : _logger(logger) {}

std::string ProfileManager::buildProfilePath(const std::string& username) const {
    return Path::USERS_DIR + username + Files::PROFILE;
}

Profile ProfileManager::loadProfile(const std::string& username) {
    std::ifstream file(buildProfilePath(username));
    if (!file) throw FileException(Error::FILE_OPEN_FAILED);
    std::string line;
    std::string storedUsername;
    std::string displayName;
    std::string bio;
    int postCount = 0;
    std::string usernameKey = ProfileFields::USERNAME + Separator::FIELD;
    std::string displayKey = ProfileFields::DISPLAY_NAME + Separator::FIELD;
    std::string bioKey = ProfileFields::BIO + Separator::FIELD;
    std::string postCountKey = ProfileFields::POST_COUNT + Separator::FIELD;
    while (std::getline(file, line)) {
        if (line.find(usernameKey) == 0)
            storedUsername = line.substr(usernameKey.length());
        else if (line.find(displayKey) == 0)
            displayName = line.substr(displayKey.length());
        else if (line.find(bioKey) == 0)
            bio = line.substr(bioKey.length());
        else if (line.find(postCountKey) == 0)
            postCount = std::stoi(line.substr(postCountKey.length()));
    }
    file.close();
    return Profile(storedUsername, displayName, bio, postCount);
}

void ProfileManager::saveProfile(const Profile& profile) {
    std::string profilePath = buildProfilePath(profile.getUsername());
    std::ifstream readFile(profilePath);
    if (!readFile) throw FileException(Error::FILE_OPEN_FAILED);
    std::string line;
    std::string password;
    std::string passwordKey = ProfileFields::PASSWORD + Separator::FIELD;
    while (std::getline(readFile, line)) {
        if (line.find(passwordKey) == 0) {
            password = line.substr(passwordKey.length());
            break;
        }
    }
    readFile.close();
    std::ofstream writeFile(profilePath);
    if (!writeFile) throw FileException(Error::FILE_WRITE_FAILED);
    writeFile << ProfileFields::USERNAME << Separator::FIELD << profile.getUsername() << Separator::NEWLINE_CHAR
              << ProfileFields::PASSWORD << Separator::FIELD << password << Separator::NEWLINE_CHAR
              << ProfileFields::DISPLAY_NAME << Separator::FIELD << profile.getDisplayName() << Separator::NEWLINE_CHAR
              << ProfileFields::BIO << Separator::FIELD << profile.getBio() << Separator::NEWLINE_CHAR
              << ProfileFields::POST_COUNT << Separator::FIELD << profile.getPostCount() << Separator::NEWLINE_CHAR;
    writeFile.close();
}

void ProfileManager::incrementPostCount(const std::string& username) {
    Profile profile = loadProfile(username);
    profile.setPostCount(profile.getPostCount() + 1);
    saveProfile(profile);
}
