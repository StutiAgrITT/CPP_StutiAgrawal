#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Transaction.h"
#include "IUtility.h"
#include <string>
#include <vector>

class Account {
private:
    std::string _accountNumber;
    double _balance;
    std::string _accountHolderId;
    bool _isActive;
    bool _isFrozen;
    std::string _createdDate;
    std::vector<Transaction*> _transactions;
    IUtility* _utility;
    void addTransaction(TransactionType type, double amount, double balanceAfter);

public:
    Account(std::string accountNumber, std::string accountHolderId,
            double initialDeposit, IUtility* utility);
    ~Account();

    bool deposit(double amount);
    bool withdraw(double amount);
    double getBalance();
    std::string getAccountNumber();
    std::string getAccountHolderId();
    bool isActive();
    bool isFrozen();
    std::string getCreatedDate();
    void deactivate();
    void freeze();
    void unfreeze();
    
    std::vector<Transaction*> getMiniStatement(int count);
    std::vector<Transaction*> getAllTransactions();
};

#endif
