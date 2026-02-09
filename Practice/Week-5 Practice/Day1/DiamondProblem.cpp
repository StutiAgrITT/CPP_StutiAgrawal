#include <iostream>

class Person {
public: 
    int id;
};

class Student : virtual public Person {

};

class Employee : public virtual Person {

};

class TeachingAssisstant : public Student, public Employee {

};

int main() {
    TeachingAssisstant t;
    t.id = 10; //able to access it after putting virtual
    return 0;
}