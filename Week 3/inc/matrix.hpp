#ifndef MATRIX_H
#define MATRIX_H

double** createMatrix(int rows, int columns);
void getMatrixValues(double** matrix, int rows, int columns);
void freeMatrix(double** matrix, int rows);
void printMatrix(double** matrix, int rows, int columns);

#endif
