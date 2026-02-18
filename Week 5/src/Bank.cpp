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
                   std::string password, UserRole role, double initialDeposit) {
    
    if (emailExists(email)) {
        return nullptr;
    }
    
    std::string userId = generateUserId();
    User* newUser = nullptr;
    
    if (role == ACCOUNT_HOLDER) {
        newUser = new(std::nothrow) AccountHolder(userId, name, email, phone, password);
        if (!newUser) {
            return nullptr;
        }
        Account* newAccount = createAccount(userId, initialDeposit);
        if (newAccount) {
            AccountHolder* holder = dynamic_cast<AccountHolder*>(newUser);
            holder->setAccountId(newAccount->getAccountNumber());
        }
        else {
            delete newUser;
            return nullptr;
        }
    }
    else if (role == ADMIN) {
        newUser = new(std::nothrow) Admin(userId, name, email, phone, password);
        if (!newUser) return nullptr;
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
    
    Account* newAccount = new(std::nothrow) Account(accountNumber, accountHolderId, initialDeposit);
    if (!newAccount) return nullptr;
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

bool Bank::closeAccountAndDeleteUser(std::string accountNumber) {
    Account* account = getAccount(accountNumber);
    if (!account) {
        return false;
    }
    std::string holderId = account->getAccountHolderId();

    for (int accountIndex = 0; accountIndex < _accounts.size(); accountIndex++) {
        if (_accounts[accountIndex]->getAccountNumber() == accountNumber) {
            account->deactivate();
            delete _accounts[accountIndex];
            _accounts.erase(_accounts.begin() + accountIndex);
            break;
        }
    }

    for (int userIndex = 0; userIndex < _users.size(); userIndex++) {
        if (_users[userIndex]->getUserId() == holderId) {
            delete _users[userIndex];
            _users.erase(_users.begin() + userIndex);
            break;
        }
    }
    return true;
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
