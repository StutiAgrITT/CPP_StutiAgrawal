#include <iostream>
#include <set>

int main() {
    std::set<int> s;

    s.insert(5);
    s.insert(2);
    s.insert(5); // duplicate ignored
    auto index = s.find(3);
    std::cout << *index << '\n';
    for(auto it = s.begin(); it != s.end(); ++it)
        std::cout << *it << " ";
    return 0;
}