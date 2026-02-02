#include <iostream>

// This exercise was mentioned in the quiz of learncpp chapter 14.5

class Point3d {
private:
    int m_num1;
    int m_num2;
    int m_num3;

public:
    void setValues(int n1, int n2, int n3) {
        m_num1 = n1;
        m_num2 = n2;
        m_num3 = n3;
    }

    void print() {
        std::cout << "<" << m_num1 << ", " << m_num2 << ", " << m_num3 << ">";
    }

    bool isEqual(Point3d point) {
        return (m_num1 == point.m_num1) && (m_num2 == point.m_num2) && (m_num3 == point.m_num3);
    }
};

int main()
{
    Point3d point;
    point.setValues(1, 2, 3);

    point.print();
    std::cout << '\n';

    Point3d point1{};
	point1.setValues(1, 2, 3);

	Point3d point2{};
	point2.setValues(1, 2, 3);

	std::cout << "point 1 and point 2 are" << (point1.isEqual(point2) ? "" : " not") << " equal\n";

	Point3d point3{};
	point3.setValues(3, 4, 5);

	std::cout << "point 1 and point 3 are" << (point1.isEqual(point3) ? "" : " not") << " equal\n";

    return 0;
}
