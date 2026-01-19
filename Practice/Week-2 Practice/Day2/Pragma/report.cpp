#include "report.hpp"
#include "student.hpp" //included again indirectly

int CalculateGrade() {
    return GetMarks() / 10;
}

int main() {
    int grade = CalculateGrade();
    return grade; //checking value by echo $?
                  //not using cout to avoid including iostream in .i file
}