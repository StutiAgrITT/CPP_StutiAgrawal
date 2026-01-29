#include "logger.hpp"
#include "matrix.hpp"
#include "valid_input.hpp"

double** createMatrix(int rows, int columns) {
    double** matrix = new double*[rows];
    for (int row = 0; row < rows; row++) {
        *(matrix + row) = new double[columns]{0};
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
