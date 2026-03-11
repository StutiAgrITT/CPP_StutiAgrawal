#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <sstream>
#include "Utility.h"
#include "MockLogger.h"

void simulateInput(const std::string& input) {
    static std::istringstream* stream = nullptr;
    delete stream;
    stream = new std::istringstream(input);
    std::cin.rdbuf(stream->rdbuf());
}

class GetValidIntegerTest : public ::testing::Test {
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

TEST_F(GetValidIntegerTest, AcceptsPositiveInteger) {
    simulateInput("42\n");
    EXPECT_EQ(utility->getValidInteger(), 42);
}

TEST_F(GetValidIntegerTest, AcceptsNegativeInteger) {
    simulateInput("-7\n");
    EXPECT_EQ(utility->getValidInteger(), -7);
}

TEST_F(GetValidIntegerTest, AcceptsZero) {
    simulateInput("0\n");
    EXPECT_EQ(utility->getValidInteger(), 0);
}

TEST_F(GetValidIntegerTest, RejectsLettersThenAcceptsValid) {
    simulateInput("abc\n5\n");
    EXPECT_EQ(utility->getValidInteger(), 5);
}

TEST_F(GetValidIntegerTest, RejectsDecimalThenAcceptsValid) {
    simulateInput("3.14\n8\n");
    EXPECT_EQ(utility->getValidInteger(), 8);
}

TEST_F(GetValidIntegerTest, RejectsTrailingCharsThenAcceptsValid) {
    simulateInput("5abc\n3\n");
    EXPECT_EQ(utility->getValidInteger(), 3);
}

TEST_F(GetValidIntegerTest, RejectsInvalidInputPrintsError) {
    simulateInput("abc\n1\n");
    EXPECT_CALL(*mockLogger, printError(::testing::_));
    utility->getValidInteger();
}

class GetValidStringTest : public ::testing::Test {
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

TEST_F(GetValidStringTest, ReturnsCorrectString) {
    simulateInput("hello\n");
    EXPECT_EQ(utility->getValidString(), "hello");
}

TEST_F(GetValidStringTest, TrimsLeadingSpaces) {
    simulateInput("   hello\n");
    EXPECT_EQ(utility->getValidString(), "hello");
}

TEST_F(GetValidStringTest, TrimsTrailingSpaces) {
    simulateInput("hello   \n");
    EXPECT_EQ(utility->getValidString(), "hello");
}

TEST_F(GetValidStringTest, TrimsLeadingAndTrailingSpaces) {
    simulateInput("   hello world   \n");
    EXPECT_EQ(utility->getValidString(), "hello world");
}

TEST_F(GetValidStringTest, ReturnsEmptyStringOnBlankLine) {
    simulateInput("   \n");
    EXPECT_EQ(utility->getValidString(), "");
}

class GetValidFilenameTest : public ::testing::Test {
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

TEST_F(GetValidFilenameTest, AcceptsSimpleName) {
    simulateInput("MySongs\n");
    EXPECT_EQ(utility->getValidFilename(), "MySongs");
}

TEST_F(GetValidFilenameTest, AcceptsNameWithSpaces) {
    simulateInput("My Playlist\n");
    EXPECT_EQ(utility->getValidFilename(), "My Playlist");
}

TEST_F(GetValidFilenameTest, AcceptsNameWithNumbers) {
    simulateInput("Playlist2024\n");
    EXPECT_EQ(utility->getValidFilename(), "Playlist2024");
}

TEST_F(GetValidFilenameTest, RejectsEmptyInputThenAcceptsValid) {
    simulateInput("   \nGoodName\n");
    EXPECT_EQ(utility->getValidFilename(), "GoodName");
}

TEST_F(GetValidFilenameTest, RejectsEmptyInputPrintsError) {
    simulateInput("   \nGoodName\n");
    EXPECT_CALL(*mockLogger, printError(::testing::_));
    utility->getValidFilename();
}

class InvalidFilenameCharTest : public ::testing::TestWithParam<std::string> {
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

TEST_P(InvalidFilenameCharTest, InvalidCharTriggersRetryAndAcceptsValid) {
    simulateInput(GetParam() + "\nGoodName\n");
    EXPECT_EQ(utility->getValidFilename(), "GoodName");
}

INSTANTIATE_TEST_SUITE_P(
    InvalidFilenameChars,
    InvalidFilenameCharTest,
    ::testing::Values(
        "bad/name",
        "bad:name",
        "bad*name",
        "bad?name",
        "bad\"name",
        "bad<name",
        "bad>name",
        "bad|name",
        "bad\\name"
    )
);
