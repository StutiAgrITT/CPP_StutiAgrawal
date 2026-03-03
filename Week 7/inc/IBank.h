#ifndef IBANK_H
#define IBANK_H
#include "User.h"
#include "Account.h"
#include "Enums.h"
#include <vector>
#include <string>

class IBank {
public:
    virtual ~IBank() = default;
    virtual User* signup(std::string name, std::string email, std::string phone,
                         std::string password, UserRole role, double initialDeposit) = 0;
    virtual User* login(std::string email, std::string password) = 0;
    virtual bool emailExists(std::string email) = 0;
    virtual Account* getAccount(std::string accountNumber) = 0;
    virtual bool closeAccountAndDeleteUser(std::string accountNumber) = 0;
    virtual bool freezeAccount(std::string accountNumber) = 0;
    virtual bool unfreezeAccount(std::string accountNumber) = 0;
    virtual std::vector<Account*> getAllAccounts() = 0;
    virtual std::vector<User*> getAllUsers() = 0;
};

#endif
