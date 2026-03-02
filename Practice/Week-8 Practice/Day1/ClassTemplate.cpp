#include <iostream>

template <typename T>
class Calculator {
private:
    T value1;
    T value2;

public:
    Calculator(T v1, T v2) : value1(v1), value2(v2) {}

    T multiply() {
        return value1 * value2;
    }
};

int main() {
    Calculator<int> calc1(5, 4);
    Calculator<double> calc2(2.5, 3.5);

    std::cout << "Integer Multiplication: " << calc1.multiply() << std::endl;
    std::cout << "Double Multiplication: " << calc2.multiply() << std::endl;

    return 0;
}
