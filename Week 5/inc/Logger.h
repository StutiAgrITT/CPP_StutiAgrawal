#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>

class Logger {
private:
    Logger();
    static Logger* instance;

public:
    const std::string MSG_INVALID_INPUT = "Invalid input! Please try again.";
    const std::string MSG_INVALID_CHOICE = "Invalid choice! Please select from the menu.";
    const std::string MSG_INVALID_AMOUNT = "Invalid amount! Amount must be positive.";
    const std::string MSG_INVALID_EMAIL = "Invalid email format!";
    const std::string MSG_INVALID_CREDENTIALS = "Invalid email or password!";
    const std::string MSG_INSUFFICIENT_BALANCE = "Insufficient balance!";
    const std::string MSG_ACCOUNT_NOT_FOUND = "Account not found!";
    const std::string MSG_ACCOUNT_FROZEN = "Account is frozen! Contact admin.";
    const std::string MSG_ACCOUNT_INACTIVE = "Account is inactive!";
    const std::string MSG_EMAIL_ALREADY_EXISTS = "Email already exists! Please use a different email.";
    const std::string MSG_UNAUTHORIZED_ACCESS = "Unauthorized access!";
    const std::string MSG_NO_TRANSACTIONS = "No transactions found.";
    const std::string MSG_ACCOUNT_ALREADY_EXISTS = "You already have an account!";
    const std::string MSG_MINIMUM_DEPOSIT_REQUIRED = "Minimum deposit of Rs. 100 is required!";
    const std::string MSG_PASSWORD_TOO_SHORT = "Password must be at least 6 characters!";

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    
    static Logger* getInstance();

    void printMessage(const std::string& message);
    void printError(const std::string& errorMsg);
};

#endif