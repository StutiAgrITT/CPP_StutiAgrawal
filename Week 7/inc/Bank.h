#ifndef BANK_H
#define BANK_H

#include "IBank.h"
#include "User.h"
#include "AccountHolder.h"
#include "Admin.h"
#include "Account.h"
#include "Enums.h"
#include "ILogger.h"
#include "IUtility.h"
#include <vector>
#include <string>

class Bank : public IBank {
private:
    std::vector<Account*> _accounts;
    std::vector<User*> _users;
    int _nextAccountNumber;
    int _nextUserId;
    ILogger* _logger;
    IUtility* _utility;
    
public:
    Bank(ILogger* logger, IUtility* utility);
    ~Bank();
    User* signup(std::string name, std::string email, std::string phone,
                 std::string password, UserRole role, double initialDeposit) override;
    User* login(std::string email, std::string password) override;
    bool emailExists(std::string email) override;
    Account* createAccount(std::string accountHolderId, double initialDeposit);
    Account* getAccount(std::string accountNumber) override;
    bool closeAccountAndDeleteUser(std::string accountNumber) override;
    bool freezeAccount(std::string accountNumber) override;
    bool unfreezeAccount(std::string accountNumber) override;
    std::vector<Account*> getAllAccounts() override;
    std::vector<User*> getAllUsers() override;
    std::string generateAccountNumber();
    std::string generateUserId();
};

#endif
