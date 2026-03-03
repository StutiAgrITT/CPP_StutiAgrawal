#ifndef ACCOUNT_HOLDER_H
#define ACCOUNT_HOLDER_H

#include "User.h"

class AccountHolder : public User {
private:
    std::string _accountId;

public:
    AccountHolder(std::string userId, std::string name, std::string email,
                  std::string phone, std::string password);
    ~AccountHolder();

    std::string getRole() override;

    void setAccountId(std::string accountId);
    std::string getAccountId();
};

#endif
