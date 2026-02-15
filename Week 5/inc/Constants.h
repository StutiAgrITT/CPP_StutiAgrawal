#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

const int MIN_PASSWORD_LENGTH = 6;
const double MIN_INITIAL_DEPOSIT = 100.0;
const double MIN_TRANSACTION_AMOUNT = 1.0;
const int MINI_STATEMENT_COUNT = 5;

const std::string WELCOME = "\n========================================\n    Welcome to Bank Simulation\n========================================\n";
const std::string APP_TITLE = "Banking Management System";

const std::string MENU_LOGIN = "\n=== Main Menu ===\n1. Login\n2. Signup\n3. Exit\nEnter your choice: ";
const std::string MENU_ACCOUNT_HOLDER = "\n=== Account Holder Menu ===\n1. Create Account\n2. Deposit Money\n3. Withdraw Money\n4. Check Balance\n5. Mini Statement\n6. Bank Statement\n7. Close Account\n8. Logout\nEnter your choice: ";
const std::string MENU_ADMIN = "\n=== Admin Menu ===\n1. View All Accounts\n2. View All Users\n3. Freeze Account\n4. Unfreeze Account\n5. Delete Account\n6. Logout\nEnter your choice: ";

const std::string MENU_SELECT_ROLE = "\n=== Select Role ===\n1. Account Holder\n2. Admin\nEnter your choice: ";

const std::string PROMPT_ENTER_NAME = "Enter your name: ";
const std::string PROMPT_ENTER_EMAIL = "Enter email: ";
const std::string PROMPT_ENTER_PASSWORD = "Enter password (min 6 characters): ";
const std::string PROMPT_ENTER_PHONE = "Enter phone number: ";
const std::string PROMPT_ENTER_AMOUNT = "Enter amount: ";
const std::string PROMPT_ENTER_ACCOUNT_NUMBER = "Enter account number: ";
const std::string PROMPT_ENTER_CHOICE = "Enter your choice: ";
const std::string PROMPT_INITIAL_DEPOSIT = "Enter initial deposit (minimum 100): ";

const std::string SUCCESS_SIGNUP = "Signup successful! You can now login.";
const std::string SUCCESS_LOGIN = "Login successful! Welcome, ";
const std::string SUCCESS_LOGOUT = "Logged out successfully!";
const std::string SUCCESS_ACCOUNT_CREATED = "Account created successfully!";
const std::string SUCCESS_DEPOSIT = "Deposit successful!";
const std::string SUCCESS_WITHDRAWAL = "Withdrawal successful!";
const std::string SUCCESS_ACCOUNT_CLOSED = "Account closed successfully!";
const std::string SUCCESS_ACCOUNT_FROZEN = "Account frozen successfully!";
const std::string SUCCESS_ACCOUNT_UNFROZEN = "Account unfrozen successfully!";
const std::string SUCCESS_ACCOUNT_DELETED = "Account deleted successfully!";

const std::string INFO_GOODBYE = "\nGoodbye.\n";
const std::string INFO_CURRENT_BALANCE = "Current Balance: Rs. ";
const std::string INFO_NO_ACCOUNT = "You don't have an account yet. Please create one.";
const std::string INFO_ACCOUNT_NUMBER = "Your Account Number: ";
const std::string INFO_MINI_STATEMENT = "\n=== Mini Statement ===";
const std::string INFO_BANK_STATEMENT = "\n=== Bank Statement (All Transactions) ===";
const std::string INFO_ACCOUNT_DETAILS = "\n=== Account Details ===";
const std::string INFO_NO_USERS = "No users found in the system.";
const std::string INFO_NO_ACCOUNTS = "No accounts found in the system.";

const std::string SEPARATOR = "========================================";

#endif