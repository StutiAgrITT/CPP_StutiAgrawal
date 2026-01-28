#include <cmath>
#include <iostream>

void getSinCos(double degrees, double& sin, double* cos) {
    const double pi = 3.14159;
    double radians = degrees * (pi / (double) 180);
    sin = std::sin(radians);
    *cos = std::cos(radians);
}

int main() {
    double degrees = 45;
    double sin;
    double cos;
    double* cosPtr = &cos;
    getSinCos(degrees, sin, cosPtr);
    std::cout << "sin(x) = " << sin << ", cos(x) = " << cos << '\n';
    return 0;
}