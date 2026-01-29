#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>

extern const std::string MSG_ENTER_COLUMNS_ADD;
extern const std::string MSG_ENTER_COLS1_ROWS2_MUL;
extern const std::string MSG_ENTER_COLS2_MUL;
extern const std::string MSG_ENTER_MATRIX_1;
extern const std::string MSG_ENTER_MATRIX_2;
extern const std::string MSG_ENTER_ROWS_ADD;
extern const std::string MSG_ENTER_ROWS1_MUL;
extern const std::string MSG_ENTER_VALUE;
extern const std::string MSG_INVALID_DOUBLE;
extern const std::string MSG_INVALID_INTEGER;
extern const std::string MSG_MATRIX_ALLOCATION_FAILED;
extern const std::string MSG_RESULT_MATRIX;

void printMessage(const std::string message);
void printMessage(const std::string message, int row, int column);

#endif
