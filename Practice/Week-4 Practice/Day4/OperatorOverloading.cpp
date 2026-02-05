#include <iostream>

class Point {
    int x, y;
public:
    Point(int x=0, int y=0) : x{x}, y{y} {}

    Point operator+(const Point& p) {
        return Point(x + p.x, y + p.y);
    }

    void display() {
        std::cout << x << ", " << y << '\n';
    }
};

int main() {
    Point p1(1, 2), p2(3, 4);
    Point p3 = p1 + p2;
    p3.display();
}
