#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#define SQUARE(x) ((x)*(x))

int Add(int a, int b) {
    return a + b;
}

int Subtract(int a, int b);

int Multiply(int a, int b){
    return a * b;
}

const double PI = 3.1415;

double AreaCircle(int radius) {
    return PI * radius * radius;
}

#endif