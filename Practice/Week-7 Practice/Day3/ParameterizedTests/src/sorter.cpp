#include "sorter.h"
#include <algorithm>

std::vector<int> Sorter::sortVector(const std::vector<int>& input) {
    std::vector<int> result = input;
    std::sort(result.begin(), result.end());
    return result;
}