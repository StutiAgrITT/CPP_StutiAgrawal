#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Student {
    std::string name;
    int marks;
};

int main() {
    std::vector<Student> students = {
        {"Jake", 85},
        {"Amy", 92},
        {"Charles", 78}
    };

    std::sort(students.begin(), students.end(),
        [](const Student& a, const Student& b) {
            return a.marks > b.marks;
        });

    for (const Student& s : students) {
        std::cout << s.name << " - " << s.marks << std::endl;
    }

    return 0;
}