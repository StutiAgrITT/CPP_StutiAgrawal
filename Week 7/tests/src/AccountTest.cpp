#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Account.h"
#include "MockUtility.h"

class AccountTest : public ::testing::Test {
protected:
    ::testing::NiceMock<MockUtility>* mockUtility;
    Account* account;

    void SetUp() override {
        mockUtility = new ::testing::NiceMock<MockUtility>();

        ON_CALL(*mockUtility, getCurrentDateTime())
            .WillByDefault(::testing::Return("2026-01-01"));

        account = new Account("ACC1001", "USR1", 500.0, mockUtility);
    }

    void TearDown() override {
        delete account;
        delete mockUtility;
    }
};

TEST_F(AccountTest, InitialBalanceIsCorrect) {
    EXPECT_DOUBLE_EQ(account->getBalance(), 500.0);
}

TEST_F(AccountTest, AccountNumberIsCorrect) {
    EXPECT_EQ(account->getAccountNumber(), "ACC1001");
}

TEST_F(AccountTest, AccountHolderIdIsCorrect) {
    EXPECT_EQ(account->getAccountHolderId(), "USR1");
}

TEST_F(AccountTest, AccountIsActiveOnCreation) {
    EXPECT_TRUE(account->isActive());
}

TEST_F(AccountTest, AccountIsNotFrozenOnCreation) {
    EXPECT_FALSE(account->isFrozen());
}

TEST_F(AccountTest, CreatedDateIsCorrect) {
    EXPECT_EQ(account->getCreatedDate(), "2026-01-01");
}

TEST_F(AccountTest, OpeningTransactionRecordedOnCreation) {
    EXPECT_EQ(account->getAllTransactions().size(), 1);
}

TEST_F(AccountTest, OpeningTransactionHasCorrectType) {
    EXPECT_EQ(account->getAllTransactions()[0]->getType(), ACCOUNT_OPENING);
}

TEST_F(AccountTest, OpeningTransactionHasCorrectAmount) {
    EXPECT_DOUBLE_EQ(account->getAllTransactions()[0]->getAmount(), 500.0);
}

TEST_F(AccountTest, OpeningTransactionHasCorrectBalanceAfter) {
    EXPECT_DOUBLE_EQ(account->getAllTransactions()[0]->getBalanceAfter(), 500.0);
}

TEST_F(AccountTest, OpeningTransactionHasCorrectDateTime) {
    EXPECT_EQ(account->getAllTransactions()[0]->getDateTime(), "2026-01-01");
}

class AccountDepositValidTest : public ::testing::TestWithParam<double> {
protected:
    ::testing::NiceMock<MockUtility>* mockUtility;
    Account* account;

    void SetUp() override {
        mockUtility = new ::testing::NiceMock<MockUtility>();
        ON_CALL(*mockUtility, getCurrentDateTime())
            .WillByDefault(::testing::Return("2026-01-01"));
        account = new Account("ACC1001", "USR1", 500.0, mockUtility);
    }

    void TearDown() override {
        delete account;
        delete mockUtility;
    }
};

TEST_P(AccountDepositValidTest, ValidDepositReturnsTrue) {
    EXPECT_TRUE(account->deposit(GetParam()));
}

TEST_P(AccountDepositValidTest, ValidDepositIncreasesBalance) {
    double before = account->getBalance();
    account->deposit(GetParam());
    EXPECT_DOUBLE_EQ(account->getBalance(), before + GetParam());
}

TEST_P(AccountDepositValidTest, ValidDepositAddsTransaction) {
    account->deposit(GetParam());
    EXPECT_EQ(account->getAllTransactions().size(), 2);
}

INSTANTIATE_TEST_SUITE_P(
    ValidDepositAmounts,
    AccountDepositValidTest,
    ::testing::Values(0.01, 1.0, 100.0, 500.0, 99999.99)
);

class AccountDepositInvalidTest : public ::testing::TestWithParam<double> {
protected:
    ::testing::NiceMock<MockUtility>* mockUtility;
    Account* account;

    void SetUp() override {
        mockUtility = new ::testing::NiceMock<MockUtility>();
        ON_CALL(*mockUtility, getCurrentDateTime())
            .WillByDefault(::testing::Return("2026-01-01"));
        account = new Account("ACC1001", "USR1", 500.0, mockUtility);
    }

    void TearDown() override {
        delete account;
        delete mockUtility;
    }
};

TEST_P(AccountDepositInvalidTest, InvalidDepositReturnsFalse) {
    EXPECT_FALSE(account->deposit(GetParam()));
}

TEST_P(AccountDepositInvalidTest, InvalidDepositDoesNotChangeBalance) {
    account->deposit(GetParam());
    EXPECT_DOUBLE_EQ(account->getBalance(), 500.0);
}

TEST_P(AccountDepositInvalidTest, InvalidDepositDoesNotAddTransaction) {
    account->deposit(GetParam());
    EXPECT_EQ(account->getAllTransactions().size(), 1);
}

INSTANTIATE_TEST_SUITE_P(
    InvalidDepositAmounts,
    AccountDepositInvalidTest,
    ::testing::Values(0.0, -0.01, -1.0, -100.0, -99999.99)
);

TEST_F(AccountTest, DepositOnFrozenAccountReturnsFalse) {
    account->freeze();
    EXPECT_FALSE(account->deposit(100.0));
}

TEST_F(AccountTest, DepositOnFrozenAccountDoesNotChangeBalance) {
    account->freeze();
    account->deposit(100.0);
    EXPECT_DOUBLE_EQ(account->getBalance(), 500.0);
}

TEST_F(AccountTest, DepositOnFrozenAccountDoesNotAddTransaction) {
    account->freeze();
    account->deposit(100.0);
    EXPECT_EQ(account->getAllTransactions().size(), 1);
}

TEST_F(AccountTest, DepositOnInactiveAccountReturnsFalse) {
    account->deactivate();
    EXPECT_FALSE(account->deposit(100.0));
}

TEST_F(AccountTest, DepositOnInactiveAccountDoesNotChangeBalance) {
    account->deactivate();
    account->deposit(100.0);
    EXPECT_DOUBLE_EQ(account->getBalance(), 500.0);
}

TEST_F(AccountTest, DepositOnInactiveAccountDoesNotAddTransaction) {
    account->deactivate();
    account->deposit(100.0);
    EXPECT_EQ(account->getAllTransactions().size(), 2);
}

class AccountWithdrawValidTest : public ::testing::TestWithParam<double> {
protected:
    ::testing::NiceMock<MockUtility>* mockUtility;
    Account* account;

    void SetUp() override {
        mockUtility = new ::testing::NiceMock<MockUtility>();
        ON_CALL(*mockUtility, getCurrentDateTime())
            .WillByDefault(::testing::Return("2026-01-01"));
        account = new Account("ACC1001", "USR1", 500.0, mockUtility);
    }

    void TearDown() override {
        delete account;
        delete mockUtility;
    }
};

TEST_P(AccountWithdrawValidTest, ValidWithdrawReturnsTrue) {
    EXPECT_TRUE(account->withdraw(GetParam()));
}

TEST_P(AccountWithdrawValidTest, ValidWithdrawDecreasesBalance) {
    double before = account->getBalance();
    account->withdraw(GetParam());
    EXPECT_DOUBLE_EQ(account->getBalance(), before - GetParam());
}

TEST_P(AccountWithdrawValidTest, ValidWithdrawAddsTransaction) {
    account->withdraw(GetParam());
    EXPECT_EQ(account->getAllTransactions().size(), 2);
}

INSTANTIATE_TEST_SUITE_P(
    ValidWithdrawAmounts,
    AccountWithdrawValidTest,
    ::testing::Values(0.01, 1.0, 100.0, 499.99, 500.0)
);

class AccountWithdrawInvalidTest : public ::testing::TestWithParam<double> {
protected:
    ::testing::NiceMock<MockUtility>* mockUtility;
    Account* account;

    void SetUp() override {
        mockUtility = new ::testing::NiceMock<MockUtility>();
        ON_CALL(*mockUtility, getCurrentDateTime())
            .WillByDefault(::testing::Return("2026-01-01"));
        account = new Account("ACC1001", "USR1", 500.0, mockUtility);
    }

    void TearDown() override {
        delete account;
        delete mockUtility;
    }
};

TEST_P(AccountWithdrawInvalidTest, InvalidWithdrawReturnsFalse) {
    EXPECT_FALSE(account->withdraw(GetParam()));
}

TEST_P(AccountWithdrawInvalidTest, InvalidWithdrawDoesNotChangeBalance) {
    account->withdraw(GetParam());
    EXPECT_DOUBLE_EQ(account->getBalance(), 500.0);
}

TEST_P(AccountWithdrawInvalidTest, InvalidWithdrawDoesNotAddTransaction) {
    account->withdraw(GetParam());
    EXPECT_EQ(account->getAllTransactions().size(), 1);
}

INSTANTIATE_TEST_SUITE_P(
    InvalidWithdrawAmounts,
    AccountWithdrawInvalidTest,
    ::testing::Values(0.0, -0.01, -1.0, -100.0, 500.01, 99999.99)
);

TEST_F(AccountTest, WithdrawOnFrozenAccountReturnsFalse) {
    account->freeze();
    EXPECT_FALSE(account->withdraw(100.0));
}

TEST_F(AccountTest, WithdrawOnFrozenAccountDoesNotChangeBalance) {
    account->freeze();
    account->withdraw(100.0);
    EXPECT_DOUBLE_EQ(account->getBalance(), 500.0);
}

TEST_F(AccountTest, WithdrawOnFrozenAccountDoesNotAddTransaction) {
    account->freeze();
    account->withdraw(100.0);
    EXPECT_EQ(account->getAllTransactions().size(), 1);
}

TEST_F(AccountTest, WithdrawOnInactiveAccountReturnsFalse) {
    account->deactivate();
    EXPECT_FALSE(account->withdraw(100.0));
}

TEST_F(AccountTest, WithdrawOnInactiveAccountDoesNotChangeBalance) {
    account->deactivate();
    account->withdraw(100.0);
    EXPECT_DOUBLE_EQ(account->getBalance(), 500.0);
}

TEST_F(AccountTest, FreezeSetsFrozenTrue) {
    account->freeze();
    EXPECT_TRUE(account->isFrozen());
}

TEST_F(AccountTest, UnfreezeSetsFrozenFalse) {
    account->freeze();
    account->unfreeze();
    EXPECT_FALSE(account->isFrozen());
}

TEST_F(AccountTest, UnfreezeAllowsDeposit) {
    account->freeze();
    account->unfreeze();
    EXPECT_TRUE(account->deposit(100.0));
}

TEST_F(AccountTest, UnfreezeAllowsWithdraw) {
    account->freeze();
    account->unfreeze();
    EXPECT_TRUE(account->withdraw(100.0));
}

TEST_F(AccountTest, FreezingAlreadyFrozenAccountStaysFrozen) {
    account->freeze();
    account->freeze();
    EXPECT_TRUE(account->isFrozen());
}

TEST_F(AccountTest, UnfreezingAlreadyUnfrozenAccountStaysUnfrozen) {
    account->unfreeze();
    EXPECT_FALSE(account->isFrozen());
}

TEST_F(AccountTest, DeactivateSetsActiveFalse) {
    account->deactivate();
    EXPECT_FALSE(account->isActive());
}

TEST_F(AccountTest, DeactivateRecordsClosureTransaction) {
    account->deactivate();
    auto transactions = account->getAllTransactions();
    EXPECT_EQ(transactions.back()->getType(), ACCOUNT_CLOSURE);
}

TEST_F(AccountTest, DeactivateClosureTransactionAmountIsZero) {
    account->deactivate();
    auto transactions = account->getAllTransactions();
    EXPECT_DOUBLE_EQ(transactions.back()->getAmount(), 0.0);
}

TEST_F(AccountTest, DeactivateClosureTransactionBalanceIsCorrect) {
    account->deactivate();
    auto transactions = account->getAllTransactions();
    EXPECT_DOUBLE_EQ(transactions.back()->getBalanceAfter(), 500.0);
}

TEST_F(AccountTest, MiniStatementReturnsAllIfLessThanLimit) {
    account->deposit(100.0);
    account->deposit(200.0);
    EXPECT_EQ(account->getMiniStatement(5).size(), 3);
}

TEST_F(AccountTest, MiniStatementRespectsLimit) {
    for (int i = 0; i < 6; i++) account->deposit(10.0);
    EXPECT_EQ(account->getMiniStatement(3).size(), 3);
}

TEST_F(AccountTest, MiniStatementReturnsLastTransactions) {
    account->deposit(111.0);
    account->deposit(222.0);
    account->deposit(333.0);

    auto mini = account->getMiniStatement(2);
    EXPECT_DOUBLE_EQ(mini[0]->getAmount(), 222.0);
    EXPECT_DOUBLE_EQ(mini[1]->getAmount(), 333.0);
}

TEST_F(AccountTest, MiniStatementWithZeroLimitReturnsEmpty) {
    EXPECT_EQ(account->getMiniStatement(0).size(), 0);
}

TEST_F(AccountTest, MiniStatementCountEqualsExactTransactions) {
    account->deposit(100.0);
    EXPECT_EQ(account->getMiniStatement(2).size(), 2);
}

TEST_F(AccountTest, GetAllTransactionsReturnsCorrectSizeAfterOperations) {
    account->deposit(100.0);
    account->withdraw(50.0);
    account->deposit(200.0);
    EXPECT_EQ(account->getAllTransactions().size(), 4);
}

TEST_F(AccountTest, GetAllTransactionsAreInCorrectOrder) {
    account->deposit(100.0);
    account->withdraw(50.0);

    auto transactions = account->getAllTransactions();
    EXPECT_EQ(transactions[0]->getType(), ACCOUNT_OPENING);
    EXPECT_EQ(transactions[1]->getType(), DEPOSIT);
    EXPECT_EQ(transactions[2]->getType(), WITHDRAWAL);
}
