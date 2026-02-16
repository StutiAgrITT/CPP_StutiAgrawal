#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

namespace Constants {
    const int MIN_PASSWORD_LENGTH = 8;
    const double MIN_INITIAL_DEPOSIT = 100.0;
    const double MIN_TRANSACTION_AMOUNT = 1.0;
    const int MINI_STATEMENT_COUNT = 5;
}

namespace Menu {
    const std::string LOGIN = "\n=== Main Menu ===\n1. Login\n2. Signup\n3. Exit\nEnter your choice: ";
    const std::string ACCOUNT_HOLDER = "\n=== Account Holder Menu ===\n1. Deposit Money\n2. Withdraw Money\n3. Check Balance\n4. Mini Statement\n5. Bank Statement\n6. Logout\nEnter your choice: ";
    const std::string ADMIN = "\n=== Admin Menu ===\n1. View All Users and Accounts\n2. Freeze Account\n3. Unfreeze Account\n4. Close Account and Delete User\n5. Logout\nEnter your choice: ";
    const std::string SELECT_ROLE = "\n=== Select Role ===\n1. Account Holder\n2. Admin\nEnter your choice: ";
}

namespace Prompt {
    const std::string ENTER_NAME = "Enter your name: ";
    const std::string ENTER_EMAIL = "Enter email: ";
    const std::string ENTER_PASSWORD = "Enter password (min 8 character, 1 uppercase, 1 lowercase, 1 digit, 1 special character): ";
    const std::string ENTER_PHONE = "Enter phone number: ";
    const std::string ENTER_AMOUNT = "Enter amount: ";
    const std::string ENTER_ACCOUNT_NUMBER = "Enter account number: ";
    const std::string ENTER_CHOICE = "Enter your choice: ";
    const std::string INITIAL_DEPOSIT = "Enter initial deposit (minimum 100): ";
}

namespace Success {
    const std::string SIGNUP = "Signup successful! Account created. You can now login.";
    const std::string LOGIN = "Login successful! Welcome, ";
    const std::string LOGOUT = "Logged out successfully!";
    const std::string ACCOUNT_CREATED = "Account created successfully!";
    const std::string DEPOSIT = "Deposit successful!";
    const std::string WITHDRAWAL = "Withdrawal successful!";
    const std::string ACCOUNT_CLOSED = "Account closed successfully!";
    const std::string ACCOUNT_FROZEN = "Account frozen successfully!";
    const std::string ACCOUNT_UNFROZEN = "Account unfrozen successfully!";
}

namespace Info {
    const std::string GOODBYE = "\nGoodbye.\n";
    const std::string WELCOME = "\n========================================\n    Welcome to Bank Simulation\n========================================\n";
    const std::string APP_TITLE = "Banking Management System";
    const std::string LOGIN = "\n=== Login ===\n";
    const std::string CURRENT_BALANCE = "Current Balance: Rs. ";
    const std::string ACCOUNT_NUMBER = "Your Account Number: ";
    const std::string MINI_STATEMENT = "\n=== Mini Statement ===";
    const std::string BANK_STATEMENT = "\n=== Bank Statement (All Transactions) ===";
    const std::string ACCOUNT_DETAILS = "\n=== Account Details ===";
    const std::string ALL_USERS = "\n=== All Users ===\n";
    const std::string NO_USERS = "No users found in the system.";
    const std::string NO_ACCOUNTS = "No accounts found in the system.";
    const std::string SEPARATOR = "========================================";
}

namespace Error {
    const std::string INVALID_INPUT = "Invalid input! Please try again.";
    const std::string INVALID_CHOICE = "Invalid choice! Please select from the menu.";
    const std::string INVALID_AMOUNT = "Invalid amount! Amount must be positive.";
    const std::string INVALID_EMAIL = "Invalid email format!";
    const std::string INVALID_PHONE = "Invalid phone number!";
    const std::string INVALID_CREDENTIALS = "Invalid email or password!";
    const std::string INSUFFICIENT_BALANCE = "Insufficient balance!";
    const std::string ACCOUNT_NOT_FOUND = "Account not found!";
    const std::string ACCOUNT_FROZEN = "Account is frozen! Contact admin.";
    const std::string ACCOUNT_INACTIVE = "Account is inactive!";
    const std::string EMAIL_ALREADY_EXISTS = "Email already exists! Please use a different email.";
    const std::string UNAUTHORIZED_ACCESS = "Unauthorized access!";
    const std::string NO_TRANSACTIONS = "No transactions found.";
    const std::string MINIMUM_DEPOSIT_REQUIRED = "Minimum deposit of Rs. 100 is required!";

    const std::string PASSWORD_TOO_SHORT = "Password must be at least 8 characters!";
    const std::string PASSWORD_NO_UPPERCASE = "Password must have atleast 1 uppercase letter!";
    const std::string PASSWORD_NO_LOWERCASE = "Password must have atleast 1 lowercase letter!";
    const std::string PASSWORD_NO_DIGIT = "Password must have atleast 1 digit!";
    const std::string PASSWORD_NO_SPECIAL = "Password must have atleast 1 special character!";
}

#endif