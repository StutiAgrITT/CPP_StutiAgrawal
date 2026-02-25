#include <gtest/gtest.h>
#include <sorter.h>

class SortParameterizedTest : public ::testing::TestWithParam<std::pair<std::vector<int>, std::vector<int>>>{
protected:
    Sorter sorter;
};

TEST_P(SortParameterizedTest, Sorting) {
    auto input = GetParam().first;
    auto expected = GetParam().second;
    EXPECT_EQ(sorter.sortVector(input), expected);
}

INSTANTIATE_TEST_SUITE_P(SortParameters, SortParameterizedTest, 
::testing::Values(
    std::make_pair(
        std::vector<int>{3, 1, 2},
        std::vector<int>{1, 2, 3}
    ),
    std::make_pair(
        std::vector<int>{1},
        std::vector<int>{1}
    ),
    std::make_pair(
        std::vector<int>{-3, -4, -5},
        std::vector<int>{-5, -4, -3}
    ),
    std::make_pair(
        std::vector<int>{1, 2},
        std::vector<int>{1, 2}
    ),
    std::make_pair(
        std::vector<int>{},
        std::vector<int>{}
    )
));
// reports as if they are separate tests