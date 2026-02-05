#include "Application.h"
#include "Matrix.h"
#include "Logger.h"
#include "Utility.h"

Application::Application() = default;

Application::~Application() = default;

void Application::run() {
    Utility* utility = Utility::getInstance();
    int choiceInt;

    while (true) {
        utility->showMenu();
        choiceInt = utility->getValidPositiveInteger();

        Choice choice = static_cast<Choice>(choiceInt);

        if (choice == EXIT) {
            return;
        }

        processChoice(choice);
    }
}

void Application::processChoice(Choice choice) {
    Logger* logger = Logger::getInstance();

    switch (choice) {
    case ADDITION:
        handleAddition();
        break;
    case MULTIPLICATION:
        handleMultiplication();
        break;
    default:
        logger->printMessage(logger->MSG_INVALID_CHOICE);
    }
}

void Application::handleAddition() {
    Logger* logger = Logger::getInstance();
    Utility* utility = Utility::getInstance();

    logger->printMessage(logger->MSG_ENTER_ROWS_ADD);
    int rows = utility->getValidPositiveInteger();

    logger->printMessage(logger->MSG_ENTER_COLUMNS_ADD);
    int columns = utility->getValidPositiveInteger();

    Matrix matrix1(rows, columns);
    Matrix matrix2(rows, columns);

    if(!matrix1.isValid() || !matrix2.isValid()) {
        return;
    }

    logger->printMessage(logger->MSG_ENTER_MATRIX_1);
    matrix1.readValues();
    logger->printMessage(logger->MSG_ENTER_MATRIX_2);
    matrix2.readValues();

    Matrix resultMatrix = matrix1 + matrix2;
    if(!resultMatrix.isValid()) {
        return;
    }

    logger->printMessage(logger->MSG_RESULT_MATRIX);
    resultMatrix.printValues();
}

void Application::handleMultiplication() {
    Logger* logger = Logger::getInstance();
    Utility* utility = Utility::getInstance();

    logger->printMessage(logger->MSG_ENTER_ROWS1_MUL);
    int rows1 = utility->getValidPositiveInteger();
    
    logger->printMessage(logger->MSG_ENTER_COLS1_ROWS2_MUL);
    int columns1Rows2 = utility->getValidPositiveInteger();

    logger->printMessage(logger->MSG_ENTER_COLS2_MUL);
    int columns2 = utility->getValidPositiveInteger();

    Matrix matrix1(rows1, columns1Rows2);
    Matrix matrix2(columns1Rows2, columns2);

    if(!matrix1.isValid() || !matrix2.isValid()) {
        return;
    }

    logger->printMessage(logger->MSG_ENTER_MATRIX_1);
    matrix1.readValues();
    logger->printMessage(logger->MSG_ENTER_MATRIX_2);
    matrix2.readValues();

    Matrix resultMatrix = matrix1 * matrix2;
    if(!resultMatrix.isValid()) {
        return;
    }

    logger->printMessage(logger->MSG_RESULT_MATRIX);
    resultMatrix.printValues();
}
