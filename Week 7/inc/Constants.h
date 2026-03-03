#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

namespace Constants {
    const int MIN_PASSWORD_LENGTH = 8;
    const double MIN_INITIAL_DEPOSIT = 100.0;
    const double MIN_TRANSACTION_AMOUNT = 1.0;
    const int MINI_STATEMENT_COUNT = 5;
    const std::string SPECIAL_CHARACTERS = "!@#$%^&*";
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
    const std::string SIGNUP = "Signup successful! Account created. You can now login.\n";
    const std::string LOGIN = "Login successful! Welcome, ";
    const std::string LOGOUT = "Logged out successfully!\n";
    const std::string ACCOUNT_CREATED = "Account created successfully!\n";
    const std::string DEPOSIT = "Deposit successful!\n";
    const std::string WITHDRAWAL = "Withdrawal successful!\n";
    const std::string ACCOUNT_CLOSED = "Account closed successfully!\n";
    const std::string ACCOUNT_FROZEN = "Account frozen successfully!\n";
    const std::string ACCOUNT_UNFROZEN = "Account unfrozen successfully!\n";
}

namespace Info {
    const std::string GOODBYE = "\nGoodbye.\n";
    const std::string WELCOME = "\n========================================\n    Welcome to Bank Simulation\n========================================\n";
    const std::string APP_TITLE = "Banking Management System\n";
    const std::string LOGIN = "\n=== Login ===\n";
    const std::string SIGNUP = "\n=== Signup ===\n";
    const std::string CURRENT_BALANCE = "Current Balance: Rs. ";
    const std::string ACCOUNT_NUMBER = "Your Account Number: ";
    const std::string MINI_STATEMENT = "\n=== Mini Statement ===\n";
    const std::string BANK_STATEMENT = "\n=== Bank Statement (All Transactions) ===\n";
    const std::string ACCOUNT_DETAILS = "\n=== Account Details ===\n";
    const std::string ALL_USERS = "\n=== All Users ===";
    const std::string NO_USERS = "No users found in the system.\n";
    const std::string NO_ACCOUNTS = "No accounts found in the system.\n";
    const std::string SEPARATOR = "\n========================================\n";
}

namespace Error {
    const std::string INVALID_INPUT = "Invalid input! Please try again.\n";
    const std::string INVALID_CHOICE = "Invalid choice! Please select from the menu.\n";
    const std::string INVALID_AMOUNT = "Invalid amount! Amount must be positive.\n";
    const std::string INVALID_EMAIL = "Invalid email format!\n";
    const std::string INVALID_PHONE = "Invalid phone number!\n";
    const std::string INVALID_CREDENTIALS = "Invalid email or password!\n";
    const std::string INSUFFICIENT_BALANCE = "Insufficient balance!\n";
    const std::string ACCOUNT_NOT_FOUND = "Account not found!\n";
    const std::string ACCOUNT_FROZEN = "Account is frozen! Contact admin.\n";
    const std::string ACCOUNT_INACTIVE = "Account is inactive!\n";
    const std::string EMAIL_ALREADY_EXISTS = "Email already exists! Please use a different email.\n";
    const std::string UNAUTHORIZED_ACCESS = "Unauthorized access!\n";
    const std::string NO_TRANSACTIONS = "No transactions found.\n";
    const std::string MINIMUM_DEPOSIT_REQUIRED = "Minimum deposit of Rs. 100 is required!\n";
    const std::string MEMORY_ALLOCATION_FAILED = "Memory allocation failed! Please try again.\n";

    const std::string PASSWORD_TOO_SHORT = "Password must be at least 8 characters!\n";
    const std::string PASSWORD_NO_UPPERCASE = "Password must have atleast 1 uppercase letter!\n";
    const std::string PASSWORD_NO_LOWERCASE = "Password must have atleast 1 lowercase letter!\n";
    const std::string PASSWORD_NO_DIGIT = "Password must have atleast 1 digit!\n";
    const std::string PASSWORD_NO_SPECIAL = "Password must have atleast 1 special character!\n";
}

#endif