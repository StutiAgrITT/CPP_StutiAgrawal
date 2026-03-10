#include <iostream>
#include <deque>

int main() {
    std::deque<int> d;

    d.push_back(2);
    d.push_front(1);
    d.push_back(3);

    for(auto it = d.begin(); it != d.end(); ++it)
        std::cout << *it << " ";
    return 0;
}