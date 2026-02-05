#include "../inc/Matrix.h"
#include "../inc/Logger.h"
#include "../inc/Utility.h"
#include <iostream>

Matrix::Matrix(int rows, int columns) 
    : m_rows {rows}, m_columns {columns}, m_values {nullptr} {
    allocateMemory();
}

Matrix::~Matrix() {
    deallocateMemory();
}

Matrix::Matrix(const Matrix& other) 
    : m_rows {other.m_rows}, m_columns {other.m_columns}, m_values {nullptr} {
    allocateMemory();
    if (m_values && other.m_values) {
        for (int row = 0; row < m_rows; row++) {
            for (int column = 0; column < m_columns; column++) {
                m_values[row][column] = other.m_values[row][column];
            }
        }
    }
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        deallocateMemory();
        
        m_rows = other.m_rows;
        m_columns = other.m_columns;
        
        allocateMemory();
        
        if (m_values && other.m_values) {
            for (int row = 0; row < m_rows; row++) {
                for (int column = 0; column < m_columns; column++) {
                    m_values[row][column] = other.m_values[row][column];
                }
            }
        }
    }
    return *this;
}

void Matrix::allocateMemory() {
    Logger* logger = Logger::getInstance();
    
    try {
        m_values = new double*[m_rows];
        for (int row = 0; row < m_rows; row++) {
            m_values[row] = new double[m_columns]{0};
        }
    }
    catch (const std::bad_alloc&) {
        logger->printMessage(logger->MSG_MATRIX_ALLOCATION_FAILED);
        m_values = nullptr;
    }
}

void Matrix::deallocateMemory() {
    if (m_values) {
        for (int row = 0; row < m_rows; row++) {
            delete[] m_values[row];
        }
        delete[] m_values;
        m_values = nullptr;
    }
}

Matrix Matrix::operator+(const Matrix& other) const {
    Matrix result(m_rows, m_columns);
    
    if (result.m_values && m_values && other.m_values) {
        for (int row = 0; row < m_rows; row++) {
            for (int column = 0; column < m_columns; column++) {
                result.m_values[row][column] = m_values[row][column] + other.m_values[row][column];
            }
        }
    }
    
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    Matrix result(m_rows, other.m_columns);
    
    if (result.m_values && m_values && other.m_values) {
        for (int row = 0; row < m_rows; row++) {
            for (int column = 0; column < other.m_columns; column++) {
                for (int k = 0; k < m_columns; k++) {
                    result.m_values[row][column] += m_values[row][k] * other.m_values[k][column];
                }
            }
        }
    }
    
    return result;
}

void Matrix::readValues() {
    Utility* utility = Utility::getInstance();
    Logger* logger = Logger::getInstance();
    
    for (int row = 0; row < m_rows; row++) {
        for (int column = 0; column < m_columns; column++) {
            logger->printMessage(logger->MSG_ENTER_VALUE, row, column);
            m_values[row][column] = utility->getValidDouble();
        }
    }
}

void Matrix::printValues() const {
    for (int row = 0; row < m_rows; row++) {
        for (int column = 0; column < m_columns; column++) {
            std::cout << m_values[row][column] << " ";
        }
        std::cout << '\n';
    }
}

bool Matrix::isValid() const {
    return m_values != nullptr;
}