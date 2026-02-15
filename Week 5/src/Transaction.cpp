#include "Transaction.h"
#include <iostream>

Transaction::Transaction(std::string transactionId, TransactionType type,
                         double amount, std::string dateTime, double balanceAfter)
           : _transactionId(transactionId), _type(type), _amount(amount),
             _dateTime(dateTime), _balanceAfter(balanceAfter) {
}

TransactionType Transaction::getType() {
    return _type;
}

std::string Transaction::getTypeString() {
    switch (_type) {
    case DEPOSIT:
        return "DEPOSIT";
    case WITHDRAWAL:
        return "WITHDRAWAL";
    case ACCOUNT_OPENING:
        return "ACCOUNT OPENING";
    case ACCOUNT_CLOSURE:
        return "ACCOUNT CLOSURE";
    default:
        return "UNKNOWN";
    }
}

double Transaction::getAmount() {
    return _amount;
}

std::string Transaction::getDateTime() {
    return 
    _dateTime;
}

double Transaction::getBalanceAfter() {
    return _balanceAfter;
}

std::string Transaction::toString() {
    return getTypeString() + " | Rs. " + std::to_string(_amount) +
           " | Balance: Rs. " = std::to_string(_balanceAfter) +
           " | " + _dateTime;
}
