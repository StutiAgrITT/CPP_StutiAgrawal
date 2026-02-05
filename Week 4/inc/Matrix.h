#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
private:
    int m_rows;
    int m_columns;
    double** m_values;

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
