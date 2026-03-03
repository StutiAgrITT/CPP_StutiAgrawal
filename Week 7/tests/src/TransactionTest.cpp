#include <gtest/gtest.h>
#include "Transaction.h"

class TransactionTest : public ::testing::Test {
protected:
    Transaction* transaction;

    void SetUp() override {
        transaction = new Transaction("TXN1", DEPOSIT, 500.0, "2026-01-01", 1000.0);
    }

    void TearDown() override {
        delete transaction;
    }
};

TEST_F(TransactionTest, GetTypeReturnsCorrectEnum) {
    EXPECT_EQ(transaction->getType(), DEPOSIT);
}

TEST_F(TransactionTest, GetAmountReturnsCorrectValue) {
    EXPECT_DOUBLE_EQ(transaction->getAmount(), 500.0);
}

TEST_F(TransactionTest, GetDateTimeReturnsCorrectValue) {
    EXPECT_EQ(transaction->getDateTime(), "2026-01-01");
}

TEST_F(TransactionTest, GetBalanceAfterReturnsCorrectValue) {
    EXPECT_DOUBLE_EQ(transaction->getBalanceAfter(), 1000.0);
}

struct TypeStringTestCase {
    TransactionType type;
    std::string expectedString;
};

class TransactionTypeStringTest : public ::testing::TestWithParam<TypeStringTestCase> {};

TEST_P(TransactionTypeStringTest, ReturnsCorrectString) {
    TypeStringTestCase testCase = GetParam();
    Transaction t("TXN1", testCase.type, 100.0, "2026-01-01", 500.0);
    EXPECT_EQ(t.getTypeString(), testCase.expectedString);
}

INSTANTIATE_TEST_SUITE_P(
    AllTransactionTypes,
    TransactionTypeStringTest,
    ::testing::Values(
        TypeStringTestCase{DEPOSIT, "DEPOSIT"},
        TypeStringTestCase{WITHDRAWAL, "WITHDRAWAL"},
        TypeStringTestCase{ACCOUNT_OPENING, "ACCOUNT OPENING"},
        TypeStringTestCase{ACCOUNT_CLOSURE, "ACCOUNT CLOSURE"}
    )
);

TEST_F(TransactionTest, ToStringContainsType) {
    EXPECT_NE(transaction->toString().find("DEPOSIT"), std::string::npos);
}

TEST_F(TransactionTest, ToStringContainsAmount) {
    EXPECT_NE(transaction->toString().find("500"), std::string::npos);
}

TEST_F(TransactionTest, ToStringContainsBalanceAfter) {
    EXPECT_NE(transaction->toString().find("1000"), std::string::npos);
}

TEST_F(TransactionTest, ToStringContainsDateTime) {
    EXPECT_NE(transaction->toString().find("2026-01-01"), std::string::npos);
}
