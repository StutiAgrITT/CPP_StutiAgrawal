#include "Admin.h"

Admin::Admin(std::string userId, std::string name, std::string email,
             std::string phone, std::string password)
    : User(userId, name, email, phone, password) {
}

Admin::~Admin() = default;

std::string Admin::getRole() {
    return "Admin";
}