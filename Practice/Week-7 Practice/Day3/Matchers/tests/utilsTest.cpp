#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "utils.h"

using namespace testing;

class UtilsFixture : public ::testing::Test {
protected:
    Utils utils;
};

TEST_F(UtilsFixture, ValueIsBetweenRange) {
    int value = utils.getValue();
    EXPECT_THAT(value, AllOf(Gt(10), Lt(20)));
}


TEST_F(UtilsFixture, GreetingStartsWithHello) {
    std::string greeting = utils.getGreeting();

    EXPECT_THAT(greeting, StartsWith("Hello"));
    EXPECT_THAT(greeting, HasSubstr("Siera"));
    EXPECT_THAT(greeting, EndsWith("ra"));
}


TEST_F(UtilsFixture, NumbersAreCorrect) {
    std::vector<int> numbers = utils.getNumbers();

    EXPECT_THAT(numbers, ElementsAre(1, 2, 3));
}


TEST_F(UtilsFixture, NumbersHaveSizeThree) {
    std::vector<int> numbers = utils.getNumbers();

    EXPECT_THAT(numbers, SizeIs(3));
}

TEST_F(UtilsFixture, NumbersContainValuesRegardlessOfOrder) {
    std::vector<int> numbers = utils.getNumbers();

    EXPECT_THAT(numbers, UnorderedElementsAre(3, 2, 1));
}
