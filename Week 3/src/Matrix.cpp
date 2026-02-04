#include "Logger.h"
#include "Matrix.h"
#include "ValidInput.h"

double** createMatrix(int rows, int columns) {
    double** matrix = nullptr;
    try {
        matrix = new double*[rows];
        for (int row = 0; row < rows; row++) {
            *(matrix + row) = new double[columns]{0};
        }
    }
    catch (const std::bad_alloc&) {
        printMessage(MSG_MATRIX_ALLOCATION_FAILED);
    }
    return matrix;
}

void getMatrixValues(double** matrix, int rows, int columns) {
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            printMessage(MSG_ENTER_VALUE, row, column);
            *(*(matrix + row) + column) = getValidDouble();
        }
    }
}

void freeMatrix(double** matrix, int rows) {
    for (int row = 0; row < rows; row++) {
        delete[] *(matrix + row);
    }
    delete[] matrix;
}

void printMatrix(double** matrix, int rows, int columns) {
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            std::cout << *(*(matrix + row) + column) << " ";
        }
        std::cout << '\n';
    }
}
