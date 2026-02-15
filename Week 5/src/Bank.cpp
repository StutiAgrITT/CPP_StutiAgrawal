#include "Bank.h"
#include "Logger.h"

Bank* Bank::instance = nullptr;

Bank::Bank() : _nextAccountNumber(1001), _nextUserId(1) {
}

Bank::~Bank() {
    for (Account* acc : _accounts) {
        delete acc;
    }
    for (User* user : _users) {
        delete user;
    }
}

Bank* Bank::getInstance() {
    if (instance == nullptr) {
        instance = new Bank();
    }
    return instance;
}

User* Bank::signup(std::string name, std::string email, std::string phone, 
                   std::string password, UserRole role) {
    
    if (emailExists(email)) {
        return nullptr;
    }
    
    std::string userId = generateUserId();
    User* newUser = nullptr;
    
    if (role == ACCOUNT_HOLDER) {
        newUser = new AccountHolder(userId, name, email, phone, password);
    }
    else if (role == ADMIN) {
        newUser = new Admin(userId, name, email, phone, password);
    }
    
    if (newUser) {
        _users.push_back(newUser);
    }
    return newUser;
}

User* Bank::login(std::string email, std::string password) {
    for (User* user : _users) {
        if (user->getEmail() == email && user->authenticate(password)) {
            return user;
        }
    }
    return nullptr;
}

bool Bank::emailExists(std::string email) {
    for (User* user : _users) {
        if (user->getEmail() == email) {
            return true;
        }
    }
    return false;
}

Account* Bank::createAccount(std::string accountHolderId, double initialDeposit) {
    std::string accountNumber = generateAccountNumber();
    
    Account* newAccount = new Account(accountNumber, accountHolderId, initialDeposit);
    _accounts.push_back(newAccount);
    
    return newAccount;
}

Account* Bank::getAccount(std::string accountNumber) {
    for (Account* account : _accounts) {
        if (account->getAccountNumber() == accountNumber) {
            return account;
        }
    }
    return nullptr;
}

bool Bank::deleteAccount(std::string accountNumber) {
    for (int i = 0; i < _accounts.size(); i++) {
        if (_accounts[i]->getAccountNumber() == accountNumber) {
            delete _accounts[i];
            _accounts.erase(_accounts.begin() + i);
            return true;
        }
    }
    return false;
}

bool Bank::freezeAccount(std::string accountNumber) {
    Account* account = getAccount(accountNumber);
    if (account) {
        account->freeze();
        return true;
    }
    return false;
}

bool Bank::unfreezeAccount(std::string accountNumber) {
    Account* account = getAccount(accountNumber);
    if (account) {
        account->unfreeze();
        return true;
    }
    return false;
}

std::vector<Account*> Bank::getAllAccounts() {
    return _accounts;
}

std::vector<User*> Bank::getAllUsers() {
    return _users;
}

std::string Bank::generateAccountNumber() {
    return "ACC" + std::to_string(_nextAccountNumber++);
}

std::string Bank::generateUserId() {
    return "USR" + std::to_string(_nextUserId++);
}
