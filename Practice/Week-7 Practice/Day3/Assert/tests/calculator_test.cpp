#include <gtest/gtest.h>
#include <calculator.h>

TEST(CalculatorTest, PositiveNumbers) {
    Calculator* ptr = nullptr;
    ASSERT_NE(ptr, nullptr);  // this will fail
    EXPECT_EQ(ptr->add(2,3), 5);  // this will NOT execute
}

TEST(CalculatorTest, NegativeNumbers) {
    Calculator calc;
    ASSERT_EQ(calc.add(-2, -3), -5);
}
