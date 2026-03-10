#include <vector>
#include <numeric>
#include <iostream>

int multiply(int a, int b) {
    return a * b;
}

int main() {
    std::vector<int> v = {5,2,8,1};

    int n = std::accumulate(v.begin(), v.end(), 1, multiply);

    std::cout << n << '\n';
    return 0;
}
