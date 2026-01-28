#include <iostream>
#include <string>

int main() {
    int s = 5;

    const int* cp = &s;      // pointer to const (low-level const)
    int* const pc = &s;      // const pointer (top-level const)
    const int* const cpc = &s; // const pointer to const

    // auto deduction
    auto a1 = cp;       // const int* (low-level const preserved)
    auto a2 = pc;       // int* (top-level const dropped)
    auto a3 = cpc;      // const int* (top-level const dropped, low-level const preserved)

    auto* b1 = cp;      // const int* (pointer reapplied)
    auto* b2 = pc;      // int* const (pointer reapplied, top-level const reapplied)
    auto* b3 = cpc;     // const int* const (pointer reapplied, top-level const reapplied)

    // Modifications
    // *a1 = "Hi";   // error, cannot modify const object
    *a2 = 10;      // ok, object modifiable
    // *a3 = "Hi";   // error, cannot modify const object

    // Pointers themselves
    // a2 = nullptr; // ok, a2 is not const
    // b2 = nullptr; // error, b2 is const pointer

    std::cout << "*a2 = " << *a2 << "\n";
    std::cout << "*b2 = " << *b2 << "\n";

    return 0;
}
