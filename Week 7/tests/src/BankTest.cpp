#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Bank.h"
#include "AccountHolder.h"
#include "Admin.h"
#include "MockLogger.h"
#include "MockUtility.h"

class BankTest : public ::testing::Test {
protected:
    ::testing::NiceMock<MockLogger>* mockLogger;
    ::testing::NiceMock<MockUtility>* mockUtility;
    Bank* bank;

    void SetUp() override {
        mockLogger  = new ::testing::NiceMock<MockLogger>();
        mockUtility = new ::testing::NiceMock<MockUtility>();

        ON_CALL(*mockUtility, getCurrentDateTime())
            .WillByDefault(::testing::Return("2026-01-01"));

        bank = new Bank(mockLogger, mockUtility);
    }

    void TearDown() override {
        delete bank;
        delete mockUtility;
        delete mockLogger;
    }

    User* signupHolder(std::string email = "stuti@gmail.com") {
        return bank->signup("Stuti Agrawal", email, "9876543210",
                            "Password@1", ACCOUNT_HOLDER, 500.0);
    }

    User* signupAdmin(std::string email = "admin@gmail.com") {
        return bank->signup("Admin User", email, "9786756453",
                            "Admin@1234", ADMIN, 0.0);
    }
};

TEST_F(BankTest, InitiallyNoAccounts) {
    EXPECT_EQ(bank->getAllAccounts().size(), 0);
}

TEST_F(BankTest, InitiallyNoUsers) {
    EXPECT_EQ(bank->getAllUsers().size(), 0);
}

TEST_F(BankTest, SignupAccountHolderReturnsValidUser) {
    User* user = signupHolder();
    EXPECT_NE(user, nullptr);
}

TEST_F(BankTest, SignupAccountHolderAddsUserToSystem) {
    signupHolder();
    EXPECT_EQ(bank->getAllUsers().size(), 1);
}

TEST_F(BankTest, SignupAccountHolderCreatesAccount) {
    signupHolder();
    EXPECT_EQ(bank->getAllAccounts().size(), 1);
}

TEST_F(BankTest, SignupAccountHolderReturnsCorrectRole) {
    User* user = signupHolder();
    EXPECT_EQ(user->getRole(), "Account Holder");
}

TEST_F(BankTest, SignupAccountHolderLinksAccountToUser) {
    User* user = signupHolder();
    AccountHolder* holder = dynamic_cast<AccountHolder*>(user);
    EXPECT_NE(holder->getAccountId(), "");
}

TEST_F(BankTest, SignupAccountHolderAccountHasCorrectBalance) {
    User* user = signupHolder();
    AccountHolder* holder = dynamic_cast<AccountHolder*>(user);
    Account* account = bank->getAccount(holder->getAccountId());
    EXPECT_DOUBLE_EQ(account->getBalance(), 500.0);
}

TEST_F(BankTest, SignupAdminReturnsValidUser) {
    User* user = signupAdmin();
    EXPECT_NE(user, nullptr);
}

TEST_F(BankTest, SignupAdminAddsUserToSystem) {
    signupAdmin();
    EXPECT_EQ(bank->getAllUsers().size(), 1);
}

TEST_F(BankTest, SignupAdminDoesNotCreateAccount) {
    signupAdmin();
    EXPECT_EQ(bank->getAllAccounts().size(), 0);
}

TEST_F(BankTest, SignupAdminReturnsCorrectRole) {
    User* user = signupAdmin();
    EXPECT_EQ(user->getRole(), "Admin");
}

class BankDuplicateEmailTest : public ::testing::TestWithParam<std::string> {
protected:
    ::testing::NiceMock<MockLogger>*  mockLogger;
    ::testing::NiceMock<MockUtility>* mockUtility;
    Bank* bank;

    void SetUp() override {
        mockLogger  = new ::testing::NiceMock<MockLogger>();
        mockUtility = new ::testing::NiceMock<MockUtility>();
        ON_CALL(*mockUtility, getCurrentDateTime())
            .WillByDefault(::testing::Return("2026-01-01"));
        bank = new Bank(mockLogger, mockUtility);
    }

    void TearDown() override {
        delete bank;
        delete mockUtility;
        delete mockLogger;
    }
};

TEST_P(BankDuplicateEmailTest, DuplicateEmailReturnsNullptr) {
    bank->signup("Stuti Agrawal", GetParam(), "9876543210",
                 "Password@1", ACCOUNT_HOLDER, 500.0);

    User* duplicate = bank->signup("Jane Doe", GetParam(), "9786756453",
                                   "Password@1", ACCOUNT_HOLDER, 500.0);
    EXPECT_EQ(duplicate, nullptr);
}

TEST_P(BankDuplicateEmailTest, DuplicateEmailDoesNotAddUser) {
    bank->signup("Stuti Agrawal", GetParam(), "9876543210",
                 "Password@1", ACCOUNT_HOLDER, 500.0);
    bank->signup("Jane Doe", GetParam(), "9786756453",
                 "Password@1", ACCOUNT_HOLDER, 500.0);

    EXPECT_EQ(bank->getAllUsers().size(), 1);
}

INSTANTIATE_TEST_SUITE_P(
    DuplicateEmails,
    BankDuplicateEmailTest,
    ::testing::Values(
        "stuti@gmail.com",
        "admin@gmail.com",
        "test@test.com"
    )
);

TEST_F(BankTest, EmailExistsReturnsTrueForExistingEmail) {
    signupHolder("stuti@gmail.com");
    EXPECT_TRUE(bank->emailExists("stuti@gmail.com"));
}

TEST_F(BankTest, EmailExistsReturnsFalseForNonExistingEmail) {
    EXPECT_FALSE(bank->emailExists("nobody@email.com"));
}

TEST_F(BankTest, EmailExistsIsCaseSensitive) {
    signupHolder("stuti@gmail.com");
    EXPECT_FALSE(bank->emailExists("STUTI@GMAIL.COM"));
}

class BankLoginInvalidTest : public ::testing::TestWithParam<std::pair<std::string, std::string>> {
protected:
    ::testing::NiceMock<MockLogger>*  mockLogger;
    ::testing::NiceMock<MockUtility>* mockUtility;
    Bank* bank;

    void SetUp() override {
        mockLogger  = new ::testing::NiceMock<MockLogger>();
        mockUtility = new ::testing::NiceMock<MockUtility>();
        ON_CALL(*mockUtility, getCurrentDateTime())
            .WillByDefault(::testing::Return("2026-01-01"));
        bank = new Bank(mockLogger, mockUtility);

        bank->signup("Stuti Agrawal", "stuti@gmail.com", "9876543210",
                     "Password@1", ACCOUNT_HOLDER, 500.0);
    }

    void TearDown() override {
        delete bank;
        delete mockUtility;
        delete mockLogger;
    }
};

TEST_P(BankLoginInvalidTest, InvalidCredentialsReturnNullptr) {
    auto [email, password] = GetParam();
    EXPECT_EQ(bank->login(email, password), nullptr);
}

INSTANTIATE_TEST_SUITE_P(
    InvalidCredentials,
    BankLoginInvalidTest,
    ::testing::Values(
        std::make_pair("stuti@gmail.com", "wrongpassword"),
        std::make_pair("wrong@email.com", "Password@1"),
        std::make_pair("wrong@email.com", "wrongpassword"),
        std::make_pair("", "Password@1"),
        std::make_pair("stuti@gmail.com", ""),
        std::make_pair("", ""),
        std::make_pair("stuti@gmail.com", "password@1"),
        std::make_pair("STUTI@GMAIL.COM", "Password@1")
    )
);

TEST_F(BankTest, LoginWithCorrectCredentialsReturnsUser) {
    signupHolder("stuti@gmail.com");
    EXPECT_NE(bank->login("stuti@gmail.com", "Password@1"), nullptr);
}

TEST_F(BankTest, LoginReturnsCorrectUser) {
    signupHolder("stuti@gmail.com");
    User* user = bank->login("stuti@gmail.com", "Password@1");
    EXPECT_EQ(user->getEmail(), "stuti@gmail.com");
}

TEST_F(BankTest, GetAccountReturnsAccountForValidNumber) {
    User* user = signupHolder();
    AccountHolder* holder = dynamic_cast<AccountHolder*>(user);
    EXPECT_NE(bank->getAccount(holder->getAccountId()), nullptr);
}

TEST_F(BankTest, GetAccountReturnsNullptrForInvalidNumber) {
    EXPECT_EQ(bank->getAccount("ACC9999"), nullptr);
}

TEST_F(BankTest, GetAccountReturnsNullptrForEmptyString) {
    EXPECT_EQ(bank->getAccount(""), nullptr);
}

TEST_F(BankTest, FreezeAccountReturnsTrueForValidAccount) {
    User* user = signupHolder();
    AccountHolder* holder = dynamic_cast<AccountHolder*>(user);
    EXPECT_TRUE(bank->freezeAccount(holder->getAccountId()));
}

TEST_F(BankTest, FreezeAccountActuallyFreezesAccount) {
    User* user = signupHolder();
    AccountHolder* holder = dynamic_cast<AccountHolder*>(user);
    bank->freezeAccount(holder->getAccountId());
    EXPECT_TRUE(bank->getAccount(holder->getAccountId())->isFrozen());
}

TEST_F(BankTest, FreezeAccountReturnsFalseForInvalidAccount) {
    EXPECT_FALSE(bank->freezeAccount("ACC9999"));
}

TEST_F(BankTest, UnfreezeAccountReturnsTrueForValidAccount) {
    User* user = signupHolder();
    AccountHolder* holder = dynamic_cast<AccountHolder*>(user);
    bank->freezeAccount(holder->getAccountId());
    EXPECT_TRUE(bank->unfreezeAccount(holder->getAccountId()));
}

TEST_F(BankTest, UnfreezeAccountActuallyUnfreezesAccount) {
    User* user = signupHolder();
    AccountHolder* holder = dynamic_cast<AccountHolder*>(user);
    bank->freezeAccount(holder->getAccountId());
    bank->unfreezeAccount(holder->getAccountId());
    EXPECT_FALSE(bank->getAccount(holder->getAccountId())->isFrozen());
}

TEST_F(BankTest, UnfreezeAccountReturnsFalseForInvalidAccount) {
    EXPECT_FALSE(bank->unfreezeAccount("ACC9999"));
}

TEST_F(BankTest, CloseAccountReturnsTrueForValidAccount) {
    User* user = signupHolder();
    AccountHolder* holder = dynamic_cast<AccountHolder*>(user);
    EXPECT_TRUE(bank->closeAccountAndDeleteUser(holder->getAccountId()));
}

TEST_F(BankTest, CloseAccountRemovesAccountFromSystem) {
    User* user = signupHolder();
    AccountHolder* holder = dynamic_cast<AccountHolder*>(user);
    std::string accountId = holder->getAccountId();
    bank->closeAccountAndDeleteUser(accountId);
    EXPECT_EQ(bank->getAllAccounts().size(), 0);
}

TEST_F(BankTest, CloseAccountRemovesUserFromSystem) {
    User* user = signupHolder();
    AccountHolder* holder = dynamic_cast<AccountHolder*>(user);
    bank->closeAccountAndDeleteUser(holder->getAccountId());
    EXPECT_EQ(bank->getAllUsers().size(), 0);
}

TEST_F(BankTest, CloseAccountReturnsFalseForInvalidAccount) {
    EXPECT_FALSE(bank->closeAccountAndDeleteUser("ACC9999"));
}

TEST_F(BankTest, CloseAccountMakesAccountUnreachable) {
    User* user = signupHolder();
    AccountHolder* holder = dynamic_cast<AccountHolder*>(user);
    std::string accountId = holder->getAccountId();
    bank->closeAccountAndDeleteUser(accountId);
    EXPECT_EQ(bank->getAccount(accountId), nullptr);
}

TEST_F(BankTest, GetAllAccountsReturnsCorrectCountAfterMultipleSignups) {
    signupHolder("user1@email.com");
    signupHolder("user2@email.com");
    signupHolder("user3@email.com");
    EXPECT_EQ(bank->getAllAccounts().size(), 3);
}

TEST_F(BankTest, GetAllUsersReturnsCorrectCountAfterMultipleSignups) {
    signupHolder("user1@email.com");
    signupAdmin("admin1@email.com");
    signupHolder("user2@email.com");
    EXPECT_EQ(bank->getAllUsers().size(), 3);
}

TEST_F(BankTest, GetAllUsersCountDecreasesAfterClose) {
    User* user = signupHolder("user1@email.com");
    signupHolder("user2@email.com");
    AccountHolder* holder = dynamic_cast<AccountHolder*>(user);
    bank->closeAccountAndDeleteUser(holder->getAccountId());
    EXPECT_EQ(bank->getAllUsers().size(), 1);
}

TEST_F(BankTest, GetAllAccountsCountDecreasesAfterClose) {
    User* user = signupHolder("user1@email.com");
    signupHolder("user2@email.com");
    AccountHolder* holder = dynamic_cast<AccountHolder*>(user);
    bank->closeAccountAndDeleteUser(holder->getAccountId());
    EXPECT_EQ(bank->getAllAccounts().size(), 1);
}
