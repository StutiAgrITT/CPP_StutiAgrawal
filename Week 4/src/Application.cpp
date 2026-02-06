#include "Application.h"
#include "Matrix.h"

Application::Application() {
    _logger = Logger::getInstance();
    _utility = Utility::getInstance();
}

Application::~Application() = default;

void Application::run() {
    int choiceInt;

    while (true) {
        _utility->showMenu();
        choiceInt = _utility->getValidPositiveInteger();

        Choice choice = static_cast<Choice>(choiceInt);

        if (choice == EXIT) {
            return;
        }

        processChoice(choice);
    }
}

void Application::processChoice(Choice choice) {
    switch (choice) {
    case ADDITION:
        handleAddition();
        break;
    case MULTIPLICATION:
        handleMultiplication();
        break;
    default:
        _logger->printMessage(_logger->MSG_INVALID_CHOICE);
    }
}

void Application::handleAddition() {
    _logger->printMessage(_logger->MSG_ENTER_ROWS_ADD);
    int rows = _utility->getValidPositiveInteger();

    _logger->printMessage(_logger->MSG_ENTER_COLUMNS_ADD);
    int columns = _utility->getValidPositiveInteger();

    Matrix matrix1(rows, columns);
    Matrix matrix2(rows, columns);

    if(!matrix1.isValid() || !matrix2.isValid()) {
        return;
    }

    _logger->printMessage(_logger->MSG_ENTER_MATRIX_1);
    matrix1.readValues();
    _logger->printMessage(_logger->MSG_ENTER_MATRIX_2);
    matrix2.readValues();

    Matrix resultMatrix = matrix1 + matrix2;
    if(!resultMatrix.isValid()) {
        return;
    }

    _logger->printMessage(_logger->MSG_RESULT_MATRIX);
    resultMatrix.printValues();
}

void Application::handleMultiplication() {
    _logger->printMessage(_logger->MSG_ENTER_ROWS1_MUL);
    int rows1 = _utility->getValidPositiveInteger();
    
    _logger->printMessage(_logger->MSG_ENTER_COLS1_ROWS2_MUL);
    int columns1Rows2 = _utility->getValidPositiveInteger();

    _logger->printMessage(_logger->MSG_ENTER_COLS2_MUL);
    int columns2 = _utility->getValidPositiveInteger();

    Matrix matrix1(rows1, columns1Rows2);
    Matrix matrix2(columns1Rows2, columns2);

    if(!matrix1.isValid() || !matrix2.isValid()) {
        return;
    }

    _logger->printMessage(_logger->MSG_ENTER_MATRIX_1);
    matrix1.readValues();
    _logger->printMessage(_logger->MSG_ENTER_MATRIX_2);
    matrix2.readValues();

    Matrix resultMatrix = matrix1 * matrix2;
    if(!resultMatrix.isValid()) {
        return;
    }

    _logger->printMessage(_logger->MSG_RESULT_MATRIX);
    resultMatrix.printValues();
}
