#include <iostream>
#include <set>

class DescendingOrder {
public:
    bool operator()(int a, int b) const {
        return a > b;
    }
};

int main() {
    std::set<int, DescendingOrder> numbers;

    numbers.insert(10);
    numbers.insert(5);
    numbers.insert(20);
    numbers.insert(15);

    for (int n : numbers) {
        std::cout << n << " ";
    }
    return 0;
}