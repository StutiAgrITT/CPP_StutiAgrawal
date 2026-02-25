#include <algorithm>
#include "sorter.h"

void bubbleSort(std::vector<int>& input) {
    for (size_t i = 0; i < input.size(); ++i) {
        for (size_t j = 0; j < input.size() - i - 1; ++j) {
            if (input[j] > input[j + 1]) {
                std::swap(input[j], input[j + 1]);
            }
        }
    }
}

void selectionSort(std::vector<int>& input) {
    for (size_t i = 0; i < input.size(); ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < input.size(); ++j) {
            if (input[j] < input[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(input[i], input[minIndex]);
    }
}