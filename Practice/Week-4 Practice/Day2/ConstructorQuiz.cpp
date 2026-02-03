#include <iostream>

class Ball {
private:
    std::string m_colour;
    double m_radius;

public:
    Ball(std::string colour, double radius) 
        : m_colour { colour }, m_radius { radius }
    {
    }

    const std::string& getColour() {return m_colour;};
    const double& getRadius() {return m_radius;};
};

void print(Ball ball) {
    std::cout << "Ball(" << ball.getColour() << ", " << ball.getRadius() << ")\n";
}

int main()
{
	Ball blue { "blue", 10.0 };
	print(blue);

	Ball red { "red", 12.0 };
	print(red);

	return 0;
}