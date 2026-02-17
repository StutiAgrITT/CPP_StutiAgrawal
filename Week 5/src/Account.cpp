#include "Account.h"
#include "Utility.h"

Account::Account(std::string accountNumber, std::string accountHolderId,
                 double initialDeposit)
    : _accountNumber(accountNumber), _accountHolderId(accountHolderId),
      _balance(initialDeposit), _isActive(true), _isFrozen(false) {

    Utility* utility = Utility::getInstance();
    _createdDate = utility->getCurrentDateTime();

    addTransaction(ACCOUNT_OPENING, initialDeposit, _balance);
}

Account::~Account() {
    for (Transaction* transaction : _transactions) {
        delete transaction;
    }
}

bool Account::deposit(double amount) {
    if (!_isActive) {
        return false;
    }

    if (_isFrozen) {
        return false;
    }

    if (amount <= 0) {
        return false;
    }

    _balance += amount;
    addTransaction(DEPOSIT, amount, _balance);
    return true;
}

bool Account::withdraw(double amount) {
    if (!_isActive) {
        return false;
    }

    if (_isFrozen) {
        return false;
    }

    if (amount <= 0) {
        return false;
    }

    if (amount > _balance) {
        return false;
    }

    _balance -= amount;
    addTransaction(WITHDRAWAL, amount, _balance);
    return true;
}

double Account::getBalance() {
    return _balance;
}

std::string Account::getAccountNumber() {
    return _accountNumber;
}

std::string Account::getAccountHolderId() {
    return _accountHolderId;
}

bool Account::isActive() {
    return _isActive;
}

bool Account::isFrozen() {
    return _isFrozen;
}

std::string Account::getCreatedDate() {
    return _createdDate;
}

void Account::deactivate() {
    _isActive = false;
    addTransaction(ACCOUNT_CLOSURE, 0, _balance);
}

void Account::freeze() {
    _isFrozen = true;
}

void Account::unfreeze() {
    _isFrozen = false;
}

std::vector<Transaction*> Account::getMiniStatement(int count) {
    std::vector<Transaction*> miniStatement;
    
    int start = _transactions.size() > count ? _transactions.size() - count : 0;
    
    for (int i = start; i < _transactions.size(); i++) {
        miniStatement.push_back(_transactions[i]);
    }
    return miniStatement;
}

std::vector<Transaction*> Account::getAllTransactions() {
    return _transactions;
}

void Account::addTransaction(TransactionType type, double amount, double balanceAfter) {
    Utility* utility = Utility::getInstance();
    std::string transactionId = "TXN" + std::to_string(_transactions.size() + 1);
    std::string dateTime = utility->getCurrentDateTime();
    
    Transaction* transaction = new(std::nothrow) Transaction(transactionId, type, amount, dateTime, balanceAfter);
    if (!transaction) return;
    _transactions.push_back(transaction);
}
