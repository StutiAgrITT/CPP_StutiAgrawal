#include "User.h"

User::User(const std::string& username, const std::string& password,
           const std::string& displayName, const std::string& bio)
    : _username(username), _password(password),_displayName(displayName), _bio(bio) {}

std::string User::getUsername() const { 
    return _username; 
}

std::string User::getPassword() const {
    return _password;
}

std::string User::getDisplayName() const {
    return _displayName; 
}

std::string User::getBio() const { 
    return _bio;
}

void User::setUsername(const std::string& username) { 
    _username = username;
}

void User::setPassword(const std::string& password) { 
    _password = password; 
}

void User::setDisplayName(const std::string& displayName) { 
    _displayName = displayName;
}

void User::setBio(const std::string& bio) {
    _bio = bio;
}
