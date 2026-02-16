#include <iostream>

class Vehicle {
protected:
    int speed;

public:
    Vehicle(int s) : speed(s) {}

    virtual void start() = 0;  // Pure virtual -> abstract class

    void showSpeed() {
        std::cout << "Speed: " << speed << std::endl;
    }

    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    Car(int s) : Vehicle(s) {}

    void start() override {
        std::cout << "Car started" << std::endl;
    }
};

int main() {
    // Vehicle v(100); error: Cannot instantiate abstract class

    Vehicle* v = new Car(120);

    v->start();
    v->showSpeed();

    delete v;
    return 0;
}
