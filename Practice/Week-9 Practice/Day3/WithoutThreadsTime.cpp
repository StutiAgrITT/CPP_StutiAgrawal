#include <iostream>
#include <chrono>

unsigned long oddSum = 0;
unsigned long evenSum = 0;

void findEven(unsigned long start, unsigned long end) {
    for (unsigned long i = start; i <= end; i++) {
        if ((i & 1) == 0) {
            evenSum += i;
        }
    }
}

void findOdd(unsigned long start, unsigned long end) {
    for (unsigned long i = start; i <= end; i++) {
        if ((i & 1) == 0) {
            evenSum += i;
        }
    }
}

int main() {
    unsigned long start = 0;
    unsigned long end = 1900000000;

    auto startTime = std::chrono::high_resolution_clock::now();
    findEven(start, end);
    findOdd(start, end);
    auto stopTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);

    std::cout << "Duration: " << duration.count()/1000000 << '\n'; //around 3-4 seconds
    return 0;
}