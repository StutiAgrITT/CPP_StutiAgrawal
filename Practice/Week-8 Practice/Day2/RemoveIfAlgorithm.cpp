#include <iostream>
#include <vector>
#include <algorithm>

// removes negative numbers

int main() {
    std::vector<int> nums = {4, -2, 7, -9, 1, -5};

    auto newEnd = std::remove_if(nums.begin(), nums.end(),
        [](int n) {
            return n < 0;
        });

    nums.erase(newEnd, nums.end());

    for (int n : nums) {
        std::cout << n << " ";
    }

    return 0;
}
