#include "multiplication.hpp"
#include "valid_input.hpp"
#include "logger.hpp"
#include "matrix.hpp"

double** multiplyMatrices(double** matrix1, double** matrix2,
                         int rows1, int columns1Rows2, int columns2) {
    double** resultMatrix = createMatrix(rows1, columns2);
    for (int row = 0; row < rows1; row++) {
        for (int column = 0; column < columns2; column++) {
            for (int colRow = 0; colRow < columns1Rows2; colRow++) {
                *(*(resultMatrix + row) + column) += (*(*(matrix1 + row) + colRow)
                                                     * *(*(matrix2 + colRow) + column));
            }
        }
    }
    return resultMatrix;
}

void multiplication() {
    printMessage(MSG_ENTER_ROWS1_MUL);
    int rows1 = getValidInteger();
    printMessage(MSG_ENTER_COLS1_ROWS2_MUL);
    int columns1Rows2 = getValidInteger();
    printMessage(MSG_ENTER_COLS2_MUL);
    int columns2 = getValidInteger();

    double** matrix1 = createMatrix(rows1, columns1Rows2);
    double** matrix2 = createMatrix(columns1Rows2, columns2);

    printMessage(MSG_ENTER_MATRIX_1);
    getMatrixValues(matrix1, rows1, columns1Rows2);
    printMessage(MSG_ENTER_MATRIX_2);
    getMatrixValues(matrix2, columns1Rows2, columns2);

    double** resultMatrix = multiplyMatrices(matrix1, matrix2, rows1, columns1Rows2, columns2);
    printMessage(MSG_RESULT_MATRIX);
    printMatrix(resultMatrix, rows1, columns2);

    freeMatrix(matrix1, rows1);
    freeMatrix(matrix2, columns1Rows2);
    freeMatrix(resultMatrix, rows1);
}
