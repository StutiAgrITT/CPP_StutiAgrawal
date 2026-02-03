#include <iostream>

class Ball 
{
private:
    double m_radius;
    std::string m_colour;

public:
    Ball(double radius)
        : Ball {"black", radius} 
    {
        
    }
    Ball(std::string colour = "black", double radius = 10) {
        m_radius = radius;
        m_colour = colour;
        std::cout << "Ball(" << m_colour << ", " << m_radius << ")\n";
    }
};

int main()
{
    Ball def{};
    Ball blue{ "blue" };
    Ball twenty{ 20.0 };
    Ball blueTwenty{ "blue", 20.0 };

    return 0;
}