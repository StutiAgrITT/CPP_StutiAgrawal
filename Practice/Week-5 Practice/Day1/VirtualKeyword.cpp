#include <iostream>

class Employee {
public:
    int a;
    Employee() {
        std::cout << "Employee\n";
    }
    virtual void calculateSalary() {
        std::cout << "Employee salary\n";
    }
};

class Developer : public Employee {
public:
    int b;
    Developer() {
        std::cout << "Developer\n";
    }
    virtual void calculateSalary() {
        std::cout << "Developer salary\n";
    }
    void printHello() {

    }
};

int main() {
    Employee* e = new Developer();
    e->calculateSalary(); //this will print employee salary problem
    std::cout << sizeof(*e) << '\n'; //1, bcs it will point to Employee, doesnt point to dynamic types
    std::cout << sizeof(Developer) << '\n';
    std::cout << sizeof(Employee) << '\n';
}
