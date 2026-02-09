#include <iostream>

class Student {
protected:
    int id;
public:
    void print() {
        std::cout << "hi\n";
    }
};

class UGStudent : Student { //default private
    int year;
public:
    UGStudent() {
        std::cout << "hello\n";
    }
    int getID(){
        return id;
    }
};

int main() {
    UGStudent a;
    //a.print(); //gives error
    std::cout <<a.getID()<< '\n';
    return 0;
}