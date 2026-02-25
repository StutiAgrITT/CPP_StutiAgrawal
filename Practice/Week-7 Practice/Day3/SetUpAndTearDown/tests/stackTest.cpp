#include <gtest/gtest.h>
#include <stack.h>

class StackFixture : public ::testing::Test {
protected:
    Stack stack;
    void SetUp() override {
        stack.push(10);
        stack.push(20);
    }
    void TearDown() override {
        std::cout << "Test Completed.\n";
    }
};

TEST_F(StackFixture, SizeAfterSet) {
    EXPECT_EQ(stack.size(), 2);
}

TEST_F(StackFixture, TopElementAfterSetup) {
    EXPECT_EQ(stack.top(), 20);
}

TEST_F(StackFixture, PopReducesSize) {
    stack.pop();
    EXPECT_EQ(stack.size(), 1);
}

TEST_F(StackFixture, PopOnEmptyThrows) {
    stack.pop();
    stack.pop();
    EXPECT_TRUE(stack.isEmpty());
    EXPECT_THROW(stack.pop(), std::out_of_range);
}
