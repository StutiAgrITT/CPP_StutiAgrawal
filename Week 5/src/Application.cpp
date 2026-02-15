#include "Application.h"
#include "Constants.h"
#include <iostream>

Application::Application() {
    _bank = Bank::getInstance();
    _logger = Logger::getInstance();
    _utility = Utility::getInstance();
    _currentUser = nullptr;
}

Application::~Application() = default;

void Application::run() {
    std::cout << WELCOME;
    while (true) {
        showLoginMenu();
    }
}

void Application::showLoginMenu() {
    std::cout << MENU_LOGIN;
    int choice = _utility->getValidInteger();
    
    switch (choice) {
        case 1:
            handleLogin();
            break;
        case 2:
            handleSignup();
            break;
        case 3:
            std::cout << INFO_GOODBYE;
            exit(0);
        default:
            _logger->printError(_logger->MSG_INVALID_CHOICE);
    }
}

void Application::handleSignup() {
    std::cout << "\n=== Signup ===\n";
    
    std::cout << PROMPT_ENTER_NAME;
    std::string name = _utility->getValidString();
    
    std::cout << PROMPT_ENTER_EMAIL;
    std::string email = _utility->getValidEmail();
    
    if (_bank->emailExists(email)) {
        _logger->printError(_logger->MSG_EMAIL_ALREADY_EXISTS);
        return;
    }
    
    std::cout << PROMPT_ENTER_PHONE;
    std::string phone = _utility->getValidString();
    
    std::cout << PROMPT_ENTER_PASSWORD;
    std::string password = _utility->getPassword();
    
    std::cout << MENU_SELECT_ROLE;
    int roleChoice = _utility->getValidInteger();
    
    UserRole role;
    if (roleChoice == 1) {
        role = UserRole::ACCOUNT_HOLDER;
    } else if (roleChoice == 2) {
        role = UserRole::ADMIN;
    } else {
        _logger->printError(_logger->MSG_INVALID_CHOICE);
        return;
    }
    
    User* newUser = _bank->signup(name, email, phone, password, role);
    
    if (newUser) {
        std::cout << SUCCESS_SIGNUP << '\n';
    } else {
        _logger->printError(_logger->MSG_INVALID_INPUT);
    }
}

void Application::handleLogin() {
    std::cout << "\n=== Login ===\n";
    
    std::cout << PROMPT_ENTER_EMAIL;
    std::string email = _utility->getValidString();
    
    std::cout << PROMPT_ENTER_PASSWORD;
    std::string password = _utility->getValidString();
    
    User* user = _bank->login(email, password);
    
    if (user) {
        _currentUser = user;
        std::cout << SUCCESS_LOGIN << user->getName() << "!\n";
        
        if (user->getRole() == "Account Holder") {
            while (_currentUser != nullptr) {
                showAccountHolderMenu();
            }
        } else if (user->getRole() == "Admin") {
            while (_currentUser != nullptr) {
                showAdminMenu();
            }
        }
    } else {
        _logger->printError(_logger->MSG_INVALID_CREDENTIALS);
    }
}

void Application::handleLogout() {
    _currentUser = nullptr;
    std::cout << SUCCESS_LOGOUT << '\n';
}

void Application::showAccountHolderMenu() {
    std::cout << MENU_ACCOUNT_HOLDER;
    int choice = _utility->getValidInteger();
    
    switch (choice) {
        case 1:
            handleCreateAccount();
            break;
        case 2:
            handleDeposit();
            break;
        case 3:
            handleWithdraw();
            break;
        case 4:
            handleCheckBalance();
            break;
        case 5:
            handleMiniStatement();
            break;
        case 6:
            handleBankStatement();
            break;
        case 7:
            handleCloseAccount();
            break;
        case 8:
            handleLogout();
            break;
        default:
            _logger->printError(_logger->MSG_INVALID_CHOICE);
    }
}

void Application::handleCreateAccount() {
    AccountHolder* holder = dynamic_cast<AccountHolder*>(_currentUser);
    
    if (!holder) {
        _logger->printError(_logger->MSG_UNAUTHORIZED_ACCESS);
        return;
    }
    
    if (holder->hasAccount()) {
        _logger->printError(_logger->MSG_ACCOUNT_ALREADY_EXISTS);
        return;
    }
    
    std::cout << PROMPT_INITIAL_DEPOSIT;
    double initialDeposit = _utility->getValidPositiveDouble();
    
    if (initialDeposit < MIN_INITIAL_DEPOSIT) {
        _logger->printError(_logger->MSG_MINIMUM_DEPOSIT_REQUIRED);
        return;
    }
    
    Account* newAccount = _bank->createAccount(holder->getUserId(), initialDeposit);
    
    if (newAccount) {
        holder->setAccountId(newAccount->getAccountNumber());
        std::cout << SUCCESS_ACCOUNT_CREATED << '\n';
        std::cout << INFO_ACCOUNT_NUMBER << newAccount->getAccountNumber() << '\n';
    }
}

void Application::handleDeposit() {
    AccountHolder* holder = dynamic_cast<AccountHolder*>(_currentUser);
    
    if (!holder || !holder->hasAccount()) {
        _logger->printError(INFO_NO_ACCOUNT);
        return;
    }
    
    Account* account = _bank->getAccount(holder->getAccountId());
    
    if (!account) {
        _logger->printError(_logger->MSG_ACCOUNT_NOT_FOUND);
        return;
    }
    
    if (!account->isActive()) {
        _logger->printError(_logger->MSG_ACCOUNT_INACTIVE);
        return;
    }
    
    if (account->isFrozen()) {
        _logger->printError(_logger->MSG_ACCOUNT_FROZEN);
        return;
    }
    
    std::cout << PROMPT_ENTER_AMOUNT;
    double amount = _utility->getValidPositiveDouble();
    
    if (account->deposit(amount)) {
        std::cout << SUCCESS_DEPOSIT << '\n';
        std::cout << INFO_CURRENT_BALANCE << account->getBalance() << '\n';
    } else {
        _logger->printError(_logger->MSG_INVALID_AMOUNT);
    }
}

void Application::handleWithdraw() {
    AccountHolder* holder = dynamic_cast<AccountHolder*>(_currentUser);
    
    if (!holder || !holder->hasAccount()) {
        _logger->printError(INFO_NO_ACCOUNT);
        return;
    }
    
    Account* account = _bank->getAccount(holder->getAccountId());
    
    if (!account) {
        _logger->printError(_logger->MSG_ACCOUNT_NOT_FOUND);
        return;
    }
    
    if (!account->isActive()) {
        _logger->printError(_logger->MSG_ACCOUNT_INACTIVE);
        return;
    }
    
    if (account->isFrozen()) {
        _logger->printError(_logger->MSG_ACCOUNT_FROZEN);
        return;
    }
    
    std::cout << PROMPT_ENTER_AMOUNT;
    double amount = _utility->getValidPositiveDouble();
    
    if (account->withdraw(amount)) {
        std::cout << SUCCESS_WITHDRAWAL << '\n';
        std::cout << INFO_CURRENT_BALANCE << account->getBalance() << '\n';
    } else {
        _logger->printError(_logger->MSG_INSUFFICIENT_BALANCE);
    }
}

void Application::handleCheckBalance() {
    AccountHolder* holder = dynamic_cast<AccountHolder*>(_currentUser);
    
    if (!holder || !holder->hasAccount()) {
        _logger->printError(INFO_NO_ACCOUNT);
        return;
    }
    
    Account* account = _bank->getAccount(holder->getAccountId());
    
    if (!account) {
        _logger->printError(_logger->MSG_ACCOUNT_NOT_FOUND);
        return;
    }
    
    displayAccountInfo(account);
}

void Application::handleMiniStatement() {
    AccountHolder* holder = dynamic_cast<AccountHolder*>(_currentUser);
    
    if (!holder || !holder->hasAccount()) {
        _logger->printError(INFO_NO_ACCOUNT);
        return;
    }
    
    Account* account = _bank->getAccount(holder->getAccountId());
    
    if (!account) {
        _logger->printError(_logger->MSG_ACCOUNT_NOT_FOUND);
        return;
    }
    
    std::vector<Transaction*> transactions = account->getMiniStatement(MINI_STATEMENT_COUNT);
    
    std::cout << INFO_MINI_STATEMENT << '\n';
    displayTransactions(transactions);
}

void Application::handleBankStatement() {
    AccountHolder* holder = dynamic_cast<AccountHolder*>(_currentUser);
    
    if (!holder || !holder->hasAccount()) {
        _logger->printError(INFO_NO_ACCOUNT);
        return;
    }
    
    Account* account = _bank->getAccount(holder->getAccountId());
    
    if (!account) {
        _logger->printError(_logger->MSG_ACCOUNT_NOT_FOUND);
        return;
    }
    
    std::vector<Transaction*> transactions = account->getAllTransactions();
    
    std::cout << INFO_BANK_STATEMENT << '\n';
    displayTransactions(transactions);
}

void Application::handleCloseAccount() {
    AccountHolder* holder = dynamic_cast<AccountHolder*>(_currentUser);
    
    if (!holder || !holder->hasAccount()) {
        _logger->printError(INFO_NO_ACCOUNT);
        return;
    }
    
    Account* account = _bank->getAccount(holder->getAccountId());
    
    if (!account) {
        _logger->printError(_logger->MSG_ACCOUNT_NOT_FOUND);
        return;
    }
    
    account->deactivate();
    holder->setAccountId("");
    
    std::cout << SUCCESS_ACCOUNT_CLOSED << '\n';
    std::cout << "Final Balance: Rs. " << account->getBalance() << '\n';
}

void Application::showAdminMenu() {
    std::cout << MENU_ADMIN;
    int choice = _utility->getValidInteger();
    
    switch (choice) {
        case 1:
            handleViewAllAccounts();
            break;
        case 2:
            handleViewAllUsers();
            break;
        case 3:
            handleFreezeAccount();
            break;
        case 4:
            handleUnfreezeAccount();
            break;
        case 5:
            handleDeleteAccount();
            break;
        case 6:
            handleLogout();
            break;
        default:
            _logger->printError(_logger->MSG_INVALID_CHOICE);
    }
}

void Application::handleViewAllAccounts() {
    std::vector<Account*> accounts = _bank->getAllAccounts();
    
    if (accounts.empty()) {
        std::cout << INFO_NO_ACCOUNTS << '\n';
        return;
    }
    
    std::cout << "\n=== All Accounts ===\n";
    for (Account* acc : accounts) {
        displayAccountInfo(acc);
        std::cout << SEPARATOR << '\n';
    }
}

void Application::handleViewAllUsers() {
    std::vector<User*> users = _bank->getAllUsers();
    
    if (users.empty()) {
        std::cout << INFO_NO_USERS << '\n';
        return;
    }
    
    std::cout << "\n=== All Users ===\n";
    for (User* user : users) {
        std::cout << "ID: " << user->getUserId() << '\n';
        std::cout << "Name: " << user->getName() << '\n';
        std::cout << "Email: " << user->getEmail() << '\n';
        std::cout << "Phone: " << user->getPhone() << '\n';
        std::cout << "Role: " << user->getRole() << '\n';
        std::cout << SEPARATOR << '\n';
    }
}

void Application::handleFreezeAccount() {
    std::cout << PROMPT_ENTER_ACCOUNT_NUMBER;
    std::string accountNumber = _utility->getValidString();
    
    if (_bank->freezeAccount(accountNumber)) {
        std::cout << SUCCESS_ACCOUNT_FROZEN << '\n';
    } else {
        _logger->printError(_logger->MSG_ACCOUNT_NOT_FOUND);
    }
}

void Application::handleUnfreezeAccount() {
    std::cout << PROMPT_ENTER_ACCOUNT_NUMBER;
    std::string accountNumber = _utility->getValidString();
    
    if (_bank->unfreezeAccount(accountNumber)) {
        std::cout << SUCCESS_ACCOUNT_UNFROZEN << '\n';
    } else {
        _logger->printError(_logger->MSG_ACCOUNT_NOT_FOUND);
    }
}

void Application::handleDeleteAccount() {
    std::cout << PROMPT_ENTER_ACCOUNT_NUMBER;
    std::string accountNumber = _utility->getValidString();
    
    if (_bank->deleteAccount(accountNumber)) {
        std::cout << SUCCESS_ACCOUNT_DELETED << '\n';
    } else {
        _logger->printError(_logger->MSG_ACCOUNT_NOT_FOUND);
    }
}

void Application::displayAccountInfo(Account* account) {
    std::cout << "\nAccount Number: " << account->getAccountNumber() << '\n';
    std::cout << "Balance: Rs. " << account->getBalance() << '\n';
    std::cout << "Status: " << (account->isActive() ? "Active" : "Closed") << '\n';
    std::cout << "Frozen: " << (account->isFrozen() ? "Yes" : "No") << '\n';
    std::cout << "Created: " << account->getCreatedDate() << '\n';
}

void Application::displayTransactions(std::vector<Transaction*> transactions) {
    if (transactions.empty()) {
        std::cout << _logger->MSG_NO_TRANSACTIONS << '\n';
        return;
    }
    
    for (Transaction* transaction : transactions) {
        std::cout << transaction->toString() << '\n';
    }
}
