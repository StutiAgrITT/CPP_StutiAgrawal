#include <gtest/gtest.h>
#include "Utility.h"
#include "MockLogger.h"
#include <sstream>

void simulateInput(const std::string& input) {
    static std::istringstream* stream = nullptr;
    delete stream;
    stream = new std::istringstream(input);
    std::cin.rdbuf(stream->rdbuf());
}

class ValidationTest : public ::testing::Test {
protected:
    ::testing::NiceMock<MockLogger>* mockLogger;
    Utility* utility;

    void SetUp() override {
        mockLogger = new ::testing::NiceMock<MockLogger>();
        utility = new Utility(mockLogger);
    }

    void TearDown() override {
        delete utility;
        delete mockLogger;
    }
};

TEST_F(ValidationTest, GetValidDoubleReturnsCorrectValue) {
    simulateInput("123.45\n");
    EXPECT_DOUBLE_EQ(utility->getValidDouble(), 123.45);
}

TEST_F(ValidationTest, GetValidDoubleAcceptsNegativeValue) {
    simulateInput("-100.0\n");
    EXPECT_DOUBLE_EQ(utility->getValidDouble(), -100.0);
}

TEST_F(ValidationTest, GetValidDoubleAcceptsZero) {
    simulateInput("0\n");
    EXPECT_DOUBLE_EQ(utility->getValidDouble(), 0.0);
}

TEST_F(ValidationTest, GetValidDoubleRejectsNonNumericThenAcceptsValid) {
    simulateInput("abc\n100.0\n");
    EXPECT_DOUBLE_EQ(utility->getValidDouble(), 100.0);
}

TEST_F(ValidationTest, GetValidPositiveDoubleAcceptsPositiveValue) {
    simulateInput("100.0\n");
    EXPECT_DOUBLE_EQ(utility->getValidPositiveDouble(), 100.0);
}

TEST_F(ValidationTest, GetValidPositiveDoubleRejectsZeroThenAcceptsValid) {
    simulateInput("0\n100.0\n");
    EXPECT_DOUBLE_EQ(utility->getValidPositiveDouble(), 100.0);
}

TEST_F(ValidationTest, GetValidPositiveDoubleRejectsNegativeThenAcceptsValid) {
    simulateInput("-100.0\n100.0\n");
    EXPECT_DOUBLE_EQ(utility->getValidPositiveDouble(), 100.0);
}

TEST_F(ValidationTest, GetValidIntegerAcceptsWholeNumber) {
    simulateInput("5\n");
    EXPECT_EQ(utility->getValidInteger(), 5);
}

TEST_F(ValidationTest, GetValidIntegerRejectsDecimalThenAcceptsValid) {
    simulateInput("5.5\n5\n");
    EXPECT_EQ(utility->getValidInteger(), 5);
}

class ValidEmailTest : public ::testing::TestWithParam<std::string> {
protected:
    ::testing::NiceMock<MockLogger>* mockLogger;
    Utility* utility;

    void SetUp() override {
        mockLogger = new ::testing::NiceMock<MockLogger>();
        utility = new Utility(mockLogger);
    }

    void TearDown() override {
        delete utility;
        delete mockLogger;
    }
};

TEST_P(ValidEmailTest, ValidEmailIsAccepted) {
    simulateInput(GetParam() + "\n");
    EXPECT_EQ(utility->getValidEmail(), GetParam());
}

INSTANTIATE_TEST_SUITE_P(
    ValidEmails,
    ValidEmailTest,
    ::testing::Values(
        "user@email.com",
        "stuti@gmail.com",
        "test123@domain.org",
        "a@b.co"
    )
);

class InvalidEmailTest : public ::testing::TestWithParam<std::pair<std::string, std::string>> {
protected:
    ::testing::NiceMock<MockLogger>* mockLogger;
    Utility* utility;

    void SetUp() override {
        mockLogger = new ::testing::NiceMock<MockLogger>();
        utility = new Utility(mockLogger);
    }

    void TearDown() override {
        delete utility;
        delete mockLogger;
    }
};

TEST_P(InvalidEmailTest, InvalidEmailTriggersRetryAndAcceptsValid) {
    auto [invalid, valid] = GetParam();
    simulateInput(invalid + "\n" + valid + "\n");
    EXPECT_EQ(utility->getValidEmail(), valid);
}

INSTANTIATE_TEST_SUITE_P(
    InvalidEmails,
    InvalidEmailTest,
    ::testing::Values(
        std::make_pair("notanemail", "user@email.com"),
        std::make_pair("@email.com", "user@email.com"),
        std::make_pair("user@", "user@email.com"),
        std::make_pair("user@email", "user@email.com"),
        std::make_pair("user@.com", "user@email.com"),
        std::make_pair("user@email.", "user@email.com"),
        std::make_pair("", "user@email.com")
    )
);

class ValidNameTest : public ::testing::TestWithParam<std::string> {
protected:
    ::testing::NiceMock<MockLogger>* mockLogger;
    Utility* utility;

    void SetUp() override {
        mockLogger = new ::testing::NiceMock<MockLogger>();
        utility = new Utility(mockLogger);
    }

    void TearDown() override {
        delete utility;
        delete mockLogger;
    }
};

TEST_P(ValidNameTest, ValidNameIsAccepted) {
    simulateInput(GetParam() + "\n");
    EXPECT_EQ(utility->getValidName(), GetParam());
}

INSTANTIATE_TEST_SUITE_P(
    ValidNames,
    ValidNameTest,
    ::testing::Values(
        "Stuti",
        "Stuti Agrawal",
        "Raymond Jacob Holt"
    )
);

class InvalidNameTest : public ::testing::TestWithParam<std::pair<std::string, std::string>> {
protected:
    ::testing::NiceMock<MockLogger>* mockLogger;
    Utility* utility;

    void SetUp() override {
        mockLogger = new ::testing::NiceMock<MockLogger>();
        utility    = new Utility(mockLogger);
    }

    void TearDown() override {
        delete utility;
        delete mockLogger;
    }
};

TEST_P(InvalidNameTest, InvalidNameTriggersRetryAndAcceptsValid) {
    auto [invalid, valid] = GetParam();
    simulateInput(invalid + "\n" + valid + "\n");
    EXPECT_EQ(utility->getValidName(), valid);
}

INSTANTIATE_TEST_SUITE_P(
    InvalidNames,
    InvalidNameTest,
    ::testing::Values(
        std::make_pair("Stuti123", "Stuti Agrawal"),
        std::make_pair("Stuti@Agrawal", "Stuti Agrawal"),
        std::make_pair("", "Stuti Agrawal"),
        std::make_pair("Stut1", "Stuti Agrawal")
    )
);

class ValidPhoneTest : public ::testing::TestWithParam<std::string> {
protected:
    ::testing::NiceMock<MockLogger>* mockLogger;
    Utility* utility;

    void SetUp() override {
        mockLogger = new ::testing::NiceMock<MockLogger>();
        utility    = new Utility(mockLogger);
    }

    void TearDown() override {
        delete utility;
        delete mockLogger;
    }
};

TEST_P(ValidPhoneTest, ValidPhoneIsAccepted) {
    simulateInput(GetParam() + "\n");
    EXPECT_EQ(utility->getValidPhone(), GetParam());
}

INSTANTIATE_TEST_SUITE_P(
    ValidPhones,
    ValidPhoneTest,
    ::testing::Values(
        "1234567890",
        "9876543210",
        "+911234567890",
        "123-456-7890"
    )
);

class InvalidPhoneTest : public ::testing::TestWithParam<std::pair<std::string, std::string>> {
protected:
    ::testing::NiceMock<MockLogger>* mockLogger;
    Utility* utility;

    void SetUp() override {
        mockLogger = new ::testing::NiceMock<MockLogger>();
        utility    = new Utility(mockLogger);
    }

    void TearDown() override {
        delete utility;
        delete mockLogger;
    }
};

TEST_P(InvalidPhoneTest, InvalidPhoneTriggersRetryAndAcceptsValid) {
    auto [invalid, valid] = GetParam();
    simulateInput(invalid + "\n" + valid + "\n");
    EXPECT_EQ(utility->getValidPhone(), valid);
}

INSTANTIATE_TEST_SUITE_P(
    InvalidPhones,
    InvalidPhoneTest,
    ::testing::Values(
        std::make_pair("123", "1234567890"),
        std::make_pair("abcdefghij", "1234567890"),
        std::make_pair("", "1234567890"),
        std::make_pair("12345@789", "1234567890")
    )
);
