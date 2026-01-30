#include "Logger.h"
#include "Matrix.h"
#include "Multiplication.h"
#include "ValidInput.h"

double** multiplyMatrices(double** matrix1, double** matrix2,
                         int rows1, int columns1Rows2, int columns2) {
    double** resultMatrix = nullptr;
    resultMatrix = createMatrix(rows1, columns2);
    
    if (resultMatrix) {
        for (int row = 0; row < rows1; row++) {
            for (int column = 0; column < columns2; column++) {
                for (int colRow = 0; colRow < columns1Rows2; colRow++) {
                    *(*(resultMatrix + row) + column) += (*(*(matrix1 + row) + colRow)
                                                         * *(*(matrix2 + colRow) + column));
                }
            }
        }
    }
    return resultMatrix;
}

void multiplication() {
    printMessage(MSG_ENTER_ROWS1_MUL);
    int rows1 = getValidPositiveInteger();
    printMessage(MSG_ENTER_COLS1_ROWS2_MUL);
    int columns1Rows2 = getValidPositiveInteger();
    printMessage(MSG_ENTER_COLS2_MUL);
    int columns2 = getValidPositiveInteger();

    double** matrix1 = createMatrix(rows1, columns1Rows2);
    double** matrix2 = createMatrix(columns1Rows2, columns2);

    if (!matrix1 || !matrix2) {
        return;
    }

    printMessage(MSG_ENTER_MATRIX_1);
    getMatrixValues(matrix1, rows1, columns1Rows2);
    printMessage(MSG_ENTER_MATRIX_2);
    getMatrixValues(matrix2, columns1Rows2, columns2);

    double** resultMatrix = multiplyMatrices(matrix1, matrix2, rows1, columns1Rows2, columns2);
    if (!resultMatrix) {
        return;
    }

    printMessage(MSG_RESULT_MATRIX);
    printMatrix(resultMatrix, rows1, columns2);

    freeMatrix(matrix1, rows1);
    freeMatrix(matrix2, columns1Rows2);
    freeMatrix(resultMatrix, rows1);
}
