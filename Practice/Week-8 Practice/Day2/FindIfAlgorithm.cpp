#include <iostream>
#include <vector>
#include <algorithm>

//finds first even number > 50

int main() {
    std::vector<int> nums = {12, 45, 67, 82, 34, 90, 23};

    auto it = std::find_if(nums.begin(), nums.end(),
        [](int n) {
            return n % 2 == 0 && n > 50;
        });

    if (it != nums.end()) {
        std::cout << "Found: " << *it << std::endl;
    }
    else {
        std::cout << "Not found" << std::endl;
    }

    return 0;
}