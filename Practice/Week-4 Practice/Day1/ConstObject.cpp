#include <iostream>

struct Date {
    int year {};
    int month {};
    int day {};

    void incrementDay() {
        ++day;
    }

    void hello() {
        std::cout << "Hello" << '\n';
    }

    void print() const {
        std::cout << year << "/" << month << "/" << day << '\n';
    }
};

int main() {
    const Date today { 2026, 02, 02 }; // const

    //today.day += 1;        // compile error: can't modify member of const object
    //today.incrementDay();  // compile error: can't call member function that modifies member of const object
    //today.hello(); // even if doesnt modify, still gives error
    today.print(); // works

    return 0;
}