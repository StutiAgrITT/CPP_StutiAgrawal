#include "addition.hpp"
#include "logger.hpp"
#include "matrix.hpp"
#include "valid_input.hpp"

double** addMatrices(double** matrix1, double** matrix2, int rows, int columns) {
    double** resultMatrix = createMatrix(rows, columns);
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            *(*(resultMatrix + row) + column) = *(*(matrix1 + row) + column)
                                                + *(*(matrix2 + row) + column);
        }
    }
    return resultMatrix;
}

void addition() {
    printMessage(MSG_ENTER_ROWS_ADD);
    int rows = getValidInteger();
    printMessage(MSG_ENTER_COLUMNS_ADD);
    int columns = getValidInteger();

    double** matrix1 = createMatrix(rows, columns);
    double** matrix2 = createMatrix(rows, columns);

    printMessage(MSG_ENTER_MATRIX_1);
    getMatrixValues(matrix1, rows, columns);
    printMessage(MSG_ENTER_MATRIX_2);
    getMatrixValues(matrix2, rows, columns);

    double** resultMatrix = addMatrices(matrix1, matrix2, rows, columns);
    printMessage(MSG_RESULT_MATRIX);
    printMatrix(resultMatrix, rows, columns);

    freeMatrix(matrix1, rows);
    freeMatrix(matrix2, rows);
    freeMatrix(resultMatrix, rows);
}
