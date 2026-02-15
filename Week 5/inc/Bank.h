#ifndef BANK_H
#define BANK_H

#include "User.h"
#include "AccountHolder.h"
#include "Admin.h"
#include "Account.h"
#include "Enums.h"
#include <vector>
#include <string>

class Bank {
private:
    static Bank* instance;
    std::vector<Account*> _accounts;
    std::vector<User*> _users;
    int _nextAccountNumber;
    int _nextUserId;

    Bank();

public:
    ~Bank();
    Bank(const Bank&) = delete;
    Bank& operator=(const Bank&) = delete;

    static Bank* getInstance();

    User* signup(std::string name, std::string email, std::string phone, 
                 std::string password, UserRole role);
    User* login(std::string email, std::string password);
    bool emailExists(std::string email);

    Account* createAccount(std::string accountHolderId, double initialDeposit);
    Account* getAccount(std::string accountNumber);
    bool deleteAccount(std::string accountNumber);
    bool freezeAccount(std::string accountNumber);
    bool unfreezeAccount(std::string accountNumber);

    std::vector<Account*> getAllAccounts();
    std::vector<User*> getAllUsers();

    std::string generateAccountNumber();
    std::string generateUserId();
};

#endif