#include <gtest/gtest.h>
#include "AccountHolder.h"
#include "Admin.h"

class UserTest : public ::testing::Test {
protected:
    AccountHolder* accountHolder;
    Admin* admin;

    void SetUp() override {
        accountHolder = new AccountHolder("USR1", "Stuti Agrawal", 
                                          "stuti@gmail.com", "9876543210", 
                                          "Password@1");
        admin = new Admin("USR2", "Admin User",
                          "admin@gmail.com", "9786756453",
                          "Admin@1234");
    }

    void TearDown() override {
        delete accountHolder;
        delete admin;
    }
};

TEST_F(UserTest, GetUserIdReturnsCorrectValue) {
    EXPECT_EQ(accountHolder->getUserId(), "USR1");
}

TEST_F(UserTest, GetNameReturnsCorrectValue) {
    EXPECT_EQ(accountHolder->getName(), "Stuti Agrawal");
}

TEST_F(UserTest, GetEmailReturnsCorrectValue) {
    EXPECT_EQ(accountHolder->getEmail(), "stuti@gmail.com");
}

TEST_F(UserTest, GetPhoneReturnsCorrectValue) {
    EXPECT_EQ(accountHolder->getPhone(), "9876543210");
}

class AuthenticateTest : public ::testing::TestWithParam<std::string> {
protected:
    AccountHolder* accountHolder;

    void SetUp() override {
        accountHolder = new AccountHolder("USR1", "Stuti Agrawal",
                                          "stuti@gmail.com", "9876543210",
                                          "Password@1");
    }

    void TearDown() override {
        delete accountHolder;
    }
};

TEST_P(AuthenticateTest, WrongPasswordReturnsFalse) {
    EXPECT_FALSE(accountHolder->authenticate(GetParam()));
}

INSTANTIATE_TEST_SUITE_P(
    WrongPasswords,
    AuthenticateTest,
    ::testing::Values(
        "wrongpassword",
        "Password@2",
        "password@1",
        "PASSWORD@1",
        "Password@",
        "",
        " "
    )
);

TEST_F(UserTest, AuthenticateReturnsTrueForCorrectPassword) {
    EXPECT_TRUE(accountHolder->authenticate("Password@1"));
}

TEST_F(UserTest, AccountHolderGetRoleReturnsCorrectValue) {
    EXPECT_EQ(accountHolder->getRole(), "Account Holder");
}

TEST_F(UserTest, AccountIdIsInitiallyEmpty) {
    EXPECT_EQ(accountHolder->getAccountId(), "");
}

TEST_F(UserTest, SetAccountIdUpdatesCorrectly) {
    accountHolder->setAccountId("ACC1001");
    EXPECT_EQ(accountHolder->getAccountId(), "ACC1001");
}

TEST_F(UserTest, SetAccountIdOverwritesPreviousValue) {
    accountHolder->setAccountId("ACC1001");
    accountHolder->setAccountId("ACC1002");
    EXPECT_EQ(accountHolder->getAccountId(), "ACC1002");
}

TEST_F(UserTest, AdminGetRoleReturnsCorrectValue) {
    EXPECT_EQ(admin->getRole(), "Admin");
}

TEST_F(UserTest, AdminGetUserIdReturnsCorrectValue) {
    EXPECT_EQ(admin->getUserId(), "USR2");
}

TEST_F(UserTest, AdminGetNameReturnsCorrectValue) {
    EXPECT_EQ(admin->getName(), "Admin User");
}

TEST_F(UserTest, AdminGetEmailReturnsCorrectValue) {
    EXPECT_EQ(admin->getEmail(), "admin@gmail.com");
}

TEST_F(UserTest, AdminAuthenticateReturnsTrueForCorrectPassword) {
    EXPECT_TRUE(admin->authenticate("Admin@1234"));
}

TEST_F(UserTest, AdminAuthenticateReturnsFalseForWrongPassword) {
    EXPECT_FALSE(admin->authenticate("wrongpassword"));
}
