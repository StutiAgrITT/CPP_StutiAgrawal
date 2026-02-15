#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Enums.h"
#include <string>

class Transaction {
private:
    std::string _transactionId;
    TransactionType _type;
    double _amount;
    std::string _dateTime;
    double _balanceAfter;

public:
    Transaction(std::string transactionId, TransactionType type,
                double amount, std::string dateTime, double balanceAfter);
    TransactionType getType();
    std::string getTypeString();
    double getAmount();
    std::string getDateTime();
    double getBalanceAfter();
    std::string toString();
};

#endif
