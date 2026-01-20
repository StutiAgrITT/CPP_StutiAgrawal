#include "college.h"

// included college.h 
// so student.h gets included
// so person.h gets included
// -> : includes 
// system.cpp -> college.h

int main() {
    College college;

    college.students[0].roll = 814;
    college.students[0].person.age = 21;
}