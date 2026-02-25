#include <iostream>
#include "calculator.h"
#include <gtest/gtest.h>

TEST(CalculatorTest, addPositive) {
    Calculator calc;
    EXPECT_EQ(calc.add(2, 3), 5);
}
TEST(CalculatorTest, addNegitive) {
    Calculator calc;
    EXPECT_EQ(calc.add(-2, -3), -5);
}
TEST(CalculatorTest, subtractPositive) {
    Calculator calc;
    EXPECT_EQ(calc.subtract(2, 3), -1);
}