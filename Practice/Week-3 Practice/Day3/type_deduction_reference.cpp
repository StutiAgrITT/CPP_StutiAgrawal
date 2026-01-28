#include <iostream>

int main() {
    const int a = 42;       // original const variable
    auto x = a;             // auto deduces type, const dropped
    const auto y = a;       // auto deduces type, then we reapply const
    auto& z = a;            // auto deduces reference, const preserved (low-level const)
    const auto& w = a;      // auto deduces reference, const preserved
    const int& b = 32;      // const reference
    auto c = b;             // auto deduces type, drops const

    std::cout << x << " " << y << " " << z << " " << w << "\n";

    // Try modifying each
    x = 10;   // ok, const dropped
    // y = 10;  // error, const reapplied
    // z = 10;  // error, cannot modify const reference
    // w = 10;  // error, cannot modify const reference
    c = 10; // const dropped

    std::cout << "x = " << x << "\n";

    return 0;
}
