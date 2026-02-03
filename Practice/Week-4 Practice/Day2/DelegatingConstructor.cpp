#include <iostream>
#include <string>

class Employee
{
private:
    std::string m_name { "???" };
    int m_id { 0 };

public:
    Employee(std::string name)
        : Employee{ name, 0 } // delegate initialization to Employee(std::string, int) constructor
    {
    }

    Employee(std::string name, int id)
        : m_name{ name }, m_id { id } // actually initializes the members
    {
        std::cout << "Employee " << m_name << " created\n";
    }

};

int main()
{
    Employee e1{ "James" };
    Employee e2{ "Dave", 42 };
}