#include <vector>
#include <algorithm>
#include <iostream>

int main() {
    std::vector<int> v = {5,2,8,1};

    std::sort(v.begin() + 1, v.end()); // 5,1,2,8

    for(int x : v)
        std::cout << x << " ";
    return 0;
}
