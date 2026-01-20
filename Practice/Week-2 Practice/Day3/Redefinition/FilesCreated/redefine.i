# 1 "redefine.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "redefine.cpp"
# 1 "multiply.h" 1



int multiply(int a, int b) {
    return a * b;
}
# 2 "redefine.cpp" 2

int multiply(int a, int b) {
    return a / b;
}

int main() {

}
