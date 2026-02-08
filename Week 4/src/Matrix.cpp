#include "Matrix.h"
#include <iostream>

Matrix::Matrix(int rows, int columns) 
    : _rows {rows}, _columns {columns}, _values {nullptr} {
    _logger = Logger::getInstance();
    _utility = Utility::getInstance();
    allocateMemory();
}

Matrix::~Matrix() {
    deallocateMemory();
}

Matrix::Matrix(const Matrix& other) 
    : _rows {other._rows}, _columns {other._columns}, _values {nullptr} {
    _logger = Logger::getInstance();
    _utility = Utility::getInstance();
    allocateMemory();

    if (_values && other._values) {
        for (int row = 0; row < _rows; row++) {
            for (int column = 0; column < _columns; column++) {
                _values[row][column] = other._values[row][column];
            }
        }
    }
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        deallocateMemory();
        
        _rows = other._rows;
        _columns = other._columns;
        
        allocateMemory();
        
        if (_values && other._values) {
            for (int row = 0; row < _rows; row++) {
                for (int column = 0; column < _columns; column++) {
                    _values[row][column] = other._values[row][column];
                }
            }
        }
    }
    return *this;
}

void Matrix::allocateMemory() {    
    try {
        _values = new double*[_rows];
        for (int row = 0; row < _rows; row++) {
            _values[row] = new double[_columns]{0};
        }
    }
    catch (const std::bad_alloc&) {
        _logger->printMessage(_logger->MSG_MATRIX_ALLOCATION_FAILED);
        _values = nullptr;
    }
}

void Matrix::deallocateMemory() {
    if (_values) {
        for (int row = 0; row < _rows; row++) {
            delete[] _values[row];
        }
        delete[] _values;
        _values = nullptr;
    }
}

Matrix Matrix::operator+(const Matrix& other) const {
    Matrix result(_rows, _columns);
    
    if (result._values && _values && other._values) {
        for (int row = 0; row < _rows; row++) {
            for (int column = 0; column < _columns; column++) {
                result._values[row][column] = _values[row][column] + other._values[row][column];
            }
        }
    }
    
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    Matrix result(_rows, other._columns);
    
    if (result._values && _values && other._values) {
        for (int row = 0; row < _rows; row++) {
            for (int column = 0; column < other._columns; column++) {
                for (int k = 0; k < _columns; k++) {
                    result._values[row][column] += _values[row][k] * other._values[k][column];
                }
            }
        }
    }
    
    return result;
}

void Matrix::readValues() {
    for (int row = 0; row < _rows; row++) {
        for (int column = 0; column < _columns; column++) {
            _logger->printMessage(_logger->MSG_ENTER_VALUE, row, column);
            _values[row][column] = _utility->getValidDouble();
        }
    }
}

void Matrix::printValues() const {
    for (int row = 0; row < _rows; row++) {
        for (int column = 0; column < _columns; column++) {
            std::cout << _values[row][column] << " ";
        }
        std::cout << '\n';
    }
}

bool Matrix::isValid() const {
    return _values != nullptr;
}