#include <gtest/gtest.h>
#include <sorter.h>

class SortTest 
    : public ::testing::TestWithParam<
        std::tuple<
            std::function<void(std::vector<int>&)>,
            std::vector<int>
        >
      > {};

TEST_P(SortTest, SortsCorrectly) {
    auto [sortFunc, input] = GetParam();

    std::vector<int> expected = input;
    std::sort(expected.begin(), expected.end());

    sortFunc(input);

    EXPECT_EQ(expected, input);
}

INSTANTIATE_TEST_SUITE_P(
    AllSortCombinations,
    SortTest,
    ::testing::Combine(
        ::testing::Values(
            bubbleSort,
            selectionSort
        ),
        ::testing::Values(
            std::vector<int>{},
            std::vector<int>{3,1,2},
            std::vector<int>{5,4,3,2,1},
            std::vector<int>{-6,-3,-5}
        )
    )
);