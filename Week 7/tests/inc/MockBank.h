#ifndef MOCK_BANK_H
#define MOCK_BANK_H
#include <gmock/gmock.h>
#include "IBank.h"

class MockBank : public IBank {
public:
    MOCK_METHOD(User*, signup, (std::string name, std::string email, std::string phone,
                                std::string password, UserRole role, double initialDeposit), (override));
    MOCK_METHOD(User*, login, (std::string email, std::string password), (override));
    MOCK_METHOD(bool, emailExists, (std::string email), (override));
    MOCK_METHOD(Account*, getAccount, (std::string accountNumber), (override));
    MOCK_METHOD(bool, closeAccountAndDeleteUser, (std::string accountNumber), (override));
    MOCK_METHOD(bool, freezeAccount, (std::string accountNumber), (override));
    MOCK_METHOD(bool, unfreezeAccount, (std::string accountNumber), (override));
    MOCK_METHOD(std::vector<Account*>, getAllAccounts, (), (override));
    MOCK_METHOD(std::vector<User*>, getAllUsers, (), (override));
};
#endif
