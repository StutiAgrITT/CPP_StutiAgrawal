#include <iostream>
#include <list>
#include <algorithm>

class GreaterThan50 {
public:
    bool operator()(int n) const {
        return n > 50;
    }
};

int main() {
    std::list<int> nums = {20, 75, 30, 90, 45};
    nums.remove_if(GreaterThan50());

    for (int n : nums) {
        std::cout << n << " ";
    }
    return 0;
}
