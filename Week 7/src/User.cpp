#include "User.h"

User::User(std::string userId, std::string name, std::string email,
           std::string phone, std::string password)
    : _userId(userId), _name(name), _email(email),
      _phone(phone), _password(password) {
}

User::~User() = default;

bool User::authenticate(std::string password) {
    return _password == password;
}

std::string User::getUserId() {
    return _userId;
}

std::string User::getName() {
    return _name;
}

std::string User::getEmail() {
    return _email;
}

std::string User::getPhone() {
    return _phone;
}