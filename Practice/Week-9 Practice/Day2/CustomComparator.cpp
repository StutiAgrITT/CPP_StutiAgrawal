#include <vector>
#include <algorithm>
#include <iostream>

bool compare(int a, int b) {
    return a > b;
}

int main() {
    std::vector<int> v = {5,2,8,1};

    std::sort(v.begin(), v.end(), compare);

    for(int x : v)
        std::cout << x << " ";
    return 0;
}
