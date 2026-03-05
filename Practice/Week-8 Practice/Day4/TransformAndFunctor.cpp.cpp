#include <iostream>
#include <vector>
#include <algorithm>

class MultiplyByThree {
public:
    int operator()(int n) const {
        return n * 3;
    }
};

int main() {
    std::vector<int> nums = {1, 2, 3, 4};
    std::transform(nums.begin(), nums.end(), nums.begin(), MultiplyByThree());

    for (int n : nums) {
        std::cout << n << " ";
    }
    return 0;
}