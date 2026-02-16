#include <iostream>

class IShape {
public:
    virtual void draw() = 0;
    virtual double area() = 0;

    virtual ~IShape() {}
};

class Circle : public IShape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    void draw() override {
        std::cout << "Drawing Circle" << std::endl;
    }

    double area() override {
        return 3.14 * radius * radius;
    }
};

int main() {
    IShape* shape = new Circle(5);

    shape->draw();
    std::cout << "Area: " << shape->area() << std::endl;

    delete shape;
    return 0;
}
