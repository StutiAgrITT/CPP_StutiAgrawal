#include "Session.h"

Session::Session() : _currentUsername(""), _isLoggedIn(false) {}

void Session::login(const std::string& username) {
    _currentUsername = username;
    _isLoggedIn = true;
}

void Session::logout() {
    _currentUsername = "";
    _isLoggedIn = false;
}

std::string Session::getUsername() const {
    return _currentUsername;
}

bool Session::isLoggedIn() const {
    return _isLoggedIn;
}
