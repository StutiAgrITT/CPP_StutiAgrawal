# 1 "report.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "report.cpp"
# 1 "report.hpp" 1
# 1 "student.hpp" 1
       

int GetMarks() {
    return 85;
}
# 2 "report.hpp" 2

int CalculateGrade();
# 2 "report.cpp" 2


int CalculateGrade() {
    return GetMarks() / 10;
}

int main() {
    int grade = CalculateGrade();
    return 0;
}
