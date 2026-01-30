#include <iostream>

#include "Addition.h"
#include "Logger.h"
#include "Menu.h"
#include "Multiplication.h"
#include "ValidInput.h"

enum Choice {
    ADDITION = 1,
    MULTIPLICATION,
    EXIT
};

void processChoice(Choice choice) {
    switch (choice) {
    case ADDITION:
        addition();
        break;
    case MULTIPLICATION:
        multiplication();
        break;
    default:
        printMessage(MSG_INVALID_CHOICE);
    }
}

void initiateMatrixOperations() {
    int choiceInt;
    while (true) {
        showMenu();
        choiceInt = getValidPositiveInteger();

        Choice choice = static_cast<Choice> (choiceInt);

        if (choice == EXIT) return;
        processChoice(choice);
    }
}

int main() {
    initiateMatrixOperations();
    return 0;
}
