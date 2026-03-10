#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    for(auto it = v.begin(); it != v.end(); ++it)
        std::cout << *it << " ";

    std::cout << "\nElement at index 1: " << v[1] << '\n'; //direct indexing
    return 0;
}