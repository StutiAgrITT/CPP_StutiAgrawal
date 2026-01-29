#include "Logger.h"

const std::string MSG_ENTER_COLUMNS_ADD = "Enter number of columns: ";
const std::string MSG_ENTER_COLS1_ROWS2_MUL = "Enter number of columns in first matrix / rows in second matrix: ";
const std::string MSG_ENTER_COLS2_MUL = "Enter number of columns in second matrix: ";
const std::string MSG_ENTER_MATRIX_1 = "Enter the values of first matrix ";
const std::string MSG_ENTER_MATRIX_2 = "Enter the values of second matrix ";
const std::string MSG_ENTER_ROWS_ADD = "Enter number of rows: ";
const std::string MSG_ENTER_ROWS1_MUL = "Enter number of rows in first matrix: ";
const std::string MSG_ENTER_VALUE = "Enter element ";
const std::string MSG_INVALID_INTEGER = "Invalid! Please enter again: ";
const std::string MSG_INVALID_CHOICE = "Invalid choice! Please enter from given options: ";
const std::string MSG_INVALID_DOUBLE = "Invalid number! Please enter again: ";
const std::string MSG_MATRIX_ALLOCATION_FAILED = "Matrix allocation failed!";
const std::string MSG_RESULT_MATRIX = "Resultant matrix: ";


void printMessage(const std::string message) {
    std::cout << message << std::endl;
}

void printMessage(const std::string message, int row, int column) {
    std::cout << message << "(" << row << ", " << column << ") : ";
}
