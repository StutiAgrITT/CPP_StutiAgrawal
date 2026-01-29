#include <iostream>

#include "Addition.h"
#include "Logger.h"
#include "Menu.h"
#include "Multiplication.h"
#include "ValidInput.h"

void processChoice(int choice) {
    switch (choice) {
    case 1:
        addition();
        break;
    case 2:
        multiplication();
        break;
    default:
        printMessage(MSG_INVALID_CHOICE);
    }
}

void initiateMatrixOperations() {
    int choice;
    while (true) {
        showMenu();
        choice = getValidPositiveInteger();

        if (choice == 3) return;
        processChoice(choice);
    }
}

int main() {
    initiateMatrixOperations();
    return 0;
}
