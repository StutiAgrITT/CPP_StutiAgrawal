#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    std::string _userId;
    std::string _name;
    std::string _email;
    std::string _phone;
    std::string _password;

public:
    User(std:: string userId, std::string name, std::string email, 
         std::string phone, std::string password);
    virtual ~User();
    virtual std::string getRole() = 0;
    bool authenticate(std::string password);

    std::string getUserId();
    std::string getName();
    std::string getEmail();
    std::string getPhone();
};

#endif
