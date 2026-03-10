

#include <vector>
#include <algorithm>
#include <iostream>

int main() {
    std::vector<int> v = {1,2,3,2,4};

    std::cout << v.size() << '\n';
    auto it = std::remove(v.begin(), v.end(), 2);
    std::cout << v.size() << '\n';
    for(int x : v)
        std::cout << x << " "; // still prints last 2.
    return 0;
}
