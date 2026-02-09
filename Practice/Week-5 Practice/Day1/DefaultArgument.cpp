#include <iostream>

class Ball {
private:
    std::string _colour;
    double _radius;

public:
    Ball(double radius) : Ball{"Black", radius} {
    }
    Ball(std::string colour = "Black", double radius = 3.0) {
        _colour = colour;
        _radius = radius;
    }

    void print() {
        std::cout << _colour << " " << _radius << '\n';
    }
};

int main() {
    Ball b1;
    Ball b2("Blue");
    Ball b3(4);
    Ball b4("Pink", 2.0);
    b1.print();
    b2.print();
    b3.print();
    b4.print();
    return 0;
}