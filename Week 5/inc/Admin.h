#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"

class Admin : public User {
public:
    Admin(std::string userId, std::string name, std::string email,
          std::string phone, std::string password);
    ~Admin();

    std::string getRole() override;;
};

#endif
