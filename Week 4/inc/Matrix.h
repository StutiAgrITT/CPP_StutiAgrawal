#ifndef MATRIX_H
#define MATRIX_H

#include "Logger.h"
#include "Utility.h"

class Matrix {
private:
    int _rows;
    int _columns;
    double** _values;

    Logger* _logger;
    Utility* _utility;

    void allocateMemory();
    void deallocateMemory();

public:
    Matrix(int rows, int columns);
    ~Matrix();
    Matrix(const Matrix& other);

    Matrix& operator=(const Matrix& other);

    Matrix operator+(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;

    void readValues();
    void printValues() const;

    bool isValid() const;
};

#endif
