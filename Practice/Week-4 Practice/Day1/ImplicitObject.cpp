#include <iostream>

struct Person {
    std::string name;
    int age;

    void kisses(Person& person) {
        std::cout << name << " kisses " << person.name << '\n';
    }
};

int main() {
    Person joe = {"Joe", 29};
    Person kate = {"Kate", 28};
    joe.kisses(kate); // joe is implicit object and kate is explicit argument
    return 0;
}