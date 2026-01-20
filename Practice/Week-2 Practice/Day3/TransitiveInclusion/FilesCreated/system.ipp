# 1 "system.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "system.cpp"
# 1 "college.h" 1



# 1 "student.h" 1



# 1 "person.h" 1



struct Person {
    int age;
};
# 5 "student.h" 2

struct Student {
    Person person;
    int roll;
};
# 5 "college.h" 2

struct College {
    Student students[100];
};
# 2 "system.cpp" 2

int main() {
    College college;

    college.students[0].roll = 814;
    college.students[0].person.age = 21;
}
