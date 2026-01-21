#include "bank_utils.h"

int main() {
    int balance = 100;
    balance = deposit(balance, 50);
    balance = withdraw(balance, 20);
    return balance;
}
