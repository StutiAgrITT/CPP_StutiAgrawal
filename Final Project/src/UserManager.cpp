#include "UserManager.h"
#include "Constants.h"
#include "Exceptions.h"
#include <fstream>
#include <filesystem>

UserManager::UserManager(Validator* validator, ILogger* logger)
    : _validator(validator), _logger(logger) {}

std::string UserManager::buildUserPath(const std::string& username) const {
    return Path::USERS_DIR + username;
}

std::string UserManager::buildProfilePath(const std::string& username) const {
    return Path::USERS_DIR + username + Files::PROFILE;
}

bool UserManager::userExists(const std::string& username) const {
    return std::filesystem::exists(buildUserPath(username));
}

bool UserManager::signUp(const std::string& username, const std::string& password,
                         const std::string& displayName, const std::string& bio) {
    if (!_validator->validateUsername(username)) return false;
    if (!_validator->validatePassword(password)) return false;
    if (userExists(username)) {
        _logger->printError(Error::USERNAME_TAKEN);
        return false;
    }

    std::string userPath = buildUserPath(username);
    std::filesystem::create_directory(userPath);

    std::string profilePath = buildProfilePath(username);
    std::ofstream profileFile(profilePath);
    if (!profileFile) throw FileException(Error::FILE_WRITE_FAILED);
    profileFile << ProfileFields::USERNAME << Separator::FIELD << username << Separator::NEWLINE_CHAR
    << ProfileFields::PASSWORD << Separator::FIELD << password << Separator::NEWLINE_CHAR
    << ProfileFields::DISPLAY_NAME << Separator::FIELD << displayName << Separator::NEWLINE_CHAR
    << ProfileFields::BIO << Separator::FIELD << bio << Separator::NEWLINE_CHAR
    << ProfileFields::POST_COUNT << Separator::FIELD << Validation::INITIAL_POST_COUNT << Separator::NEWLINE_CHAR;
    profileFile.close();

    std::ofstream postsFile(userPath + Files::POSTS);
    postsFile.close();

    std::ofstream likesFile(userPath + Files::LIKES);
    likesFile.close();
    return true;
}

bool UserManager::signIn(const std::string& username, const std::string& password) {
    if (!userExists(username)) {
        _logger->printError(Error::INVALID_CREDENTIALS);
        return false;
    }
    std::ifstream file(buildProfilePath(username));
    if (!file) throw FileException(Error::FILE_OPEN_FAILED);
    std::string line;
    std::string storedPassword;
    std::string passwordKey = ProfileFields::PASSWORD + Separator::FIELD;
    while (std::getline(file, line)) {
        if (line.find(passwordKey) == 0) {
            storedPassword = line.substr(passwordKey.length());
            break;
        }
    }
    file.close();
    if (storedPassword != password) {
        _logger->printError(Error::INVALID_CREDENTIALS);
        return false;
    }
    return true;
}
