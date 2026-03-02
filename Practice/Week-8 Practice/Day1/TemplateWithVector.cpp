#include <iostream>
#include <vector>

template <typename T>
void printVector(const std::vector<T>& vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::vector<double> decimals = {1.1, 2.2, 3.3};

    std::cout << "Integer Vector: ";
    printVector(numbers);

    std::cout << "Double Vector: ";
    printVector(decimals);

    return 0;
}
