#include <gtest/gtest.h>
#include <calculator.h>

class CalculatorFixture : public ::testing::Test {
protected:
    Calculator calc;
};

TEST_F(CalculatorFixture, PositiveNumbers) {
    EXPECT_EQ(calc.add(2, 3), 5);
}

TEST_F(CalculatorFixture, NegativeNumbers) {
    EXPECT_EQ(calc.add(-2, -3), -5);
}
