#include "AccountHolder.h"

AccountHolder::AccountHolder(std::string userId, std::string name,
                             std::string email, std::string phone,
                             std::string password)
    : User(userId, name, email, phone, password), _accountId("") {
}

std::string AccountHolder::getRole() {
    return "Account Holder";
}

void AccountHolder::setAccountId(std::string accountId) {
    _accountId = accountId;
}

bool AccountHolder::hasAccount() {
    return !(_accountId.empty());
}
