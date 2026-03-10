#include <vector>
#include <algorithm>
#include <iostream>

int main() {
    std::vector<int> v = {1,2,3,2,4};

    std::cout << v.size() << '\n';
    v.erase(std::remove(v.begin(), v.end(), 2), v.end());
    std::cout << v.size() << '\n'; //size updated
    for(int x : v)
        std::cout << x << " "; 
    return 0;
}
