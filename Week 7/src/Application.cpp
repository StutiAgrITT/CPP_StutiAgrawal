#include "Application.h"
#include "Constants.h"
#include <iostream>

Application::Application(IBank* bank, ILogger* logger, IUtility* utility)
    : _bank(bank), _logger(logger), _utility(utility),
      _currentUser(nullptr), _isRunning(true) {}

Application::~Application() = default;

void Application::run() {
    _logger->printInline(Info::WELCOME);
    while (_isRunning) {
        showLoginMenu();
    }
}

void Application::showLoginMenu() {
    _logger->printInline(Menu::LOGIN);
    int choice = _utility->getValidInteger();
    
    switch (choice) {
        case 1:
            handleLogin();
            break;
        case 2:
            handleSignup();
            break;
        case 3:
            _logger->printInline(Info::GOODBYE);
            _isRunning = false;
            break;
        default:
            _logger->printError(Error::INVALID_CHOICE);
    }
}

void Application::handleSignup() {
    _logger->printInline(Info::SIGNUP);

    UserRole role;
    while (true) {
        _logger->printInline(Menu::SELECT_ROLE);
        int roleChoice = _utility->getValidInteger();

        if (roleChoice == 1) {
            role = ACCOUNT_HOLDER;
            break;
        }
        else if (roleChoice == 2) {
            role = ADMIN;
            break;
        }
        else {
            _logger->printError(Error::INVALID_CHOICE);
        }
    }
    
    _logger->printInline(Prompt::ENTER_NAME);
    std::string name = _utility->getValidName();
    
    _logger->printInline(Prompt::ENTER_EMAIL);
    std::string email = _utility->getValidEmail();
    
    if (_bank->emailExists(email)) {
        _logger->printError(Error::EMAIL_ALREADY_EXISTS);
        return;
    }
    
    _logger->printInline(Prompt::ENTER_PHONE);
    std::string phone = _utility->getValidPhone();
    
    _logger->printInline(Prompt::ENTER_PASSWORD);
    std::string password = _utility->getPassword();

    double initialDeposit = 0;
    if (role == ACCOUNT_HOLDER) {
        _logger->printInline(Prompt::INITIAL_DEPOSIT);
        initialDeposit = _utility->getValidPositiveDouble();

        if (initialDeposit < Constants::MIN_INITIAL_DEPOSIT) {
            _logger->printError(Error::MINIMUM_DEPOSIT_REQUIRED);
            return;
        }
    }
    
    User* newUser = _bank->signup(name, email, phone, password, role, initialDeposit);
    
    if (newUser) {
        _logger->printInline(Success::SIGNUP);
        if (role == ACCOUNT_HOLDER) {
            AccountHolder* holder = dynamic_cast<AccountHolder*>(newUser);
            if (holder) {
                _logger->printInline(Info::ACCOUNT_NUMBER + holder->getAccountId() + "\n");
            }
        }
    }
    else {
        _logger->printError(Error::MEMORY_ALLOCATION_FAILED);
    }
}

void Application::handleLogin() {
    _logger->printInline(Info::LOGIN);
    
    _logger->printInline(Prompt::ENTER_EMAIL);
    std::string email = _utility->getValidString();
    
    _logger->printInline(Prompt::ENTER_PASSWORD);
    std::string password = _utility->getPassword();
    
    User* user = _bank->login(email, password);
    
    if (user) {
        _currentUser = user;
        _logger->printInline(Success::LOGIN + user->getName() + "!\n");
        
        if (user->getRole() == "Account Holder") {
            while (_currentUser != nullptr) {
                showAccountHolderMenu();
            }
        }
        else if (user->getRole() == "Admin") {
            while (_currentUser != nullptr) {
                showAdminMenu();
            }
        }
    }
    else {
        _logger->printError(Error::INVALID_CREDENTIALS);
    }
}

void Application::handleLogout() {
    _currentUser = nullptr;
    _logger->printInline(Success::LOGOUT);
}

void Application::showAccountHolderMenu() {
    _logger->printInline(Menu::ACCOUNT_HOLDER);
    int choice = _utility->getValidInteger();
    
    switch (choice) {
        case 1:
            handleDeposit();
            break;
        case 2:
            handleWithdraw();
            break;
        case 3:
            handleCheckBalance();
            break;
        case 4:
            handleMiniStatement();
            break;
        case 5:
            handleBankStatement();
            break;
        case 6:
            handleLogout();
            break;
        default:
            _logger->printError(Error::INVALID_CHOICE);
    }
}

void Application::handleDeposit() {
    AccountHolder* holder = dynamic_cast<AccountHolder*>(_currentUser);
    
    if (!holder) {
        _logger->printError(Error::UNAUTHORIZED_ACCESS);
        return;
    }
    
    Account* account = _bank->getAccount(holder->getAccountId());
    
    if (!account) {
        _logger->printError(Error::ACCOUNT_NOT_FOUND);
        return;
    }
    
    if (!account->isActive()) {
        _logger->printError(Error::ACCOUNT_INACTIVE);
        return;
    }
    
    if (account->isFrozen()) {
        _logger->printError(Error::ACCOUNT_FROZEN);
        return;
    }
    
    _logger->printInline(Prompt::ENTER_AMOUNT);
    double amount = _utility->getValidPositiveDouble();
    
    if (account->deposit(amount)) {
        _logger->printInline(Success::DEPOSIT);
        _logger->printInline(Info::CURRENT_BALANCE + std::to_string(account->getBalance()) + "\n");
    }
    else {
        _logger->printError(Error::INVALID_AMOUNT);
    }
}

void Application::handleWithdraw() {
    AccountHolder* holder = dynamic_cast<AccountHolder*>(_currentUser);
    
    if (!holder) {
        _logger->printError(Error::UNAUTHORIZED_ACCESS);
        return;
    }
    
    Account* account = _bank->getAccount(holder->getAccountId());
    
    if (!account) {
        _logger->printError(Error::ACCOUNT_NOT_FOUND);
        return;
    }
    
    if (!account->isActive()) {
        _logger->printError(Error::ACCOUNT_INACTIVE);
        return;
    }
    
    if (account->isFrozen()) {
        _logger->printError(Error::ACCOUNT_FROZEN);
        return;
    }
    
    _logger->printInline(Prompt::ENTER_AMOUNT);
    double amount = _utility->getValidPositiveDouble();
    
    if (account->withdraw(amount)) {
        _logger->printInline(Success::WITHDRAWAL);
        _logger->printInline(Info::CURRENT_BALANCE + std::to_string(account->getBalance()));
    }
    else {
        _logger->printError(Error::INSUFFICIENT_BALANCE);
    }
}

void Application::handleCheckBalance() {
    AccountHolder* holder = dynamic_cast<AccountHolder*>(_currentUser);
    
    if (!holder) {
        _logger->printError(Error::UNAUTHORIZED_ACCESS);
        return;
    }
    
    Account* account = _bank->getAccount(holder->getAccountId());
    
    if (!account) {
        _logger->printError(Error::ACCOUNT_NOT_FOUND);
        return;
    }
    
    displayAccountInfo(account);
}

void Application::handleMiniStatement() {
    AccountHolder* holder = dynamic_cast<AccountHolder*>(_currentUser);
    
    if (!holder) {
        _logger->printError(Error::UNAUTHORIZED_ACCESS);
        return;
    }
    
    Account* account = _bank->getAccount(holder->getAccountId());
    
    if (!account) {
        _logger->printError(Error::ACCOUNT_NOT_FOUND);
        return;
    }
    
    std::vector<Transaction*> transactions = account->getMiniStatement(Constants::MINI_STATEMENT_COUNT);
    
    _logger->printInline(Info::MINI_STATEMENT);
    displayTransactions(transactions);
}

void Application::handleBankStatement() {
    AccountHolder* holder = dynamic_cast<AccountHolder*>(_currentUser);
    
    if (!holder) {
        _logger->printError(Error::UNAUTHORIZED_ACCESS);
        return;
    }
    
    Account* account = _bank->getAccount(holder->getAccountId());
    
    if (!account) {
        _logger->printError(Error::ACCOUNT_NOT_FOUND);
        return;
    }
    
    std::vector<Transaction*> transactions = account->getAllTransactions();
    
    _logger->printInline(Info::BANK_STATEMENT);
    displayTransactions(transactions);
}

void Application::showAdminMenu() {
    _logger->printInline(Menu::ADMIN);
    int choice = _utility->getValidInteger();
    
    switch (choice) {
        case 1:
            handleViewAllUsersAndAccounts();
            break;
        case 2:
            handleFreezeAccount();
            break;
        case 3:
            handleUnfreezeAccount();
            break;
        case 4:
            handleCloseAccountAndDeleteUser();
            break;
        case 5:
            handleLogout();
            break;
        default:
            _logger->printError(Error::INVALID_CHOICE);
    }
}

void Application::handleViewAllUsersAndAccounts() {
    std::vector<User*> users = _bank->getAllUsers();
    
    if (users.empty()) {
        _logger->printInline(Info::NO_USERS);
        return;
    }
    
    _logger->printInline(Info::ALL_USERS);
    for (User* user : users) {
        _logger->printInline("\n" + Info::SEPARATOR);
        _logger->printInline("User ID: " + user->getUserId() + "\n");
        _logger->printInline("Name: " + user->getName() + "\n");
        _logger->printInline("Email: " + user->getEmail() + "\n");
        _logger->printInline("Phone: " + user->getPhone() + "\n");
        _logger->printInline("Role: " + user->getRole() + "\n");

        if (user->getRole() == "Account Holder") {
            AccountHolder* holder = dynamic_cast<AccountHolder*>(user);
            if (holder) {
                Account* account = _bank->getAccount(holder->getAccountId());
                if (account) {
                    _logger->printInline(Info::ACCOUNT_DETAILS);
                    displayAccountInfo(account);
                }
            }
            else {
                _logger->printInline("No account found.");
            }
        } else {
            _logger->printInline("(Admin - No account)");
        }
        _logger->printInline(Info::SEPARATOR);
    }
}

void Application::handleFreezeAccount() {
    _logger->printInline(Prompt::ENTER_ACCOUNT_NUMBER);
    std::string accountNumber = _utility->getValidString();
    
    if (_bank->freezeAccount(accountNumber)) {
        _logger->printInline(Success::ACCOUNT_FROZEN);
    } else {
        _logger->printError(Error::ACCOUNT_NOT_FOUND);
    }
}

void Application::handleUnfreezeAccount() {
    _logger->printInline(Prompt::ENTER_ACCOUNT_NUMBER);
    std::string accountNumber = _utility->getValidString();
    
    if (_bank->unfreezeAccount(accountNumber)) {
        _logger->printInline(Success::ACCOUNT_UNFROZEN);
    } else {
        _logger->printError(Error::ACCOUNT_NOT_FOUND);
    }
}

void Application::handleCloseAccountAndDeleteUser() {
    _logger->printInline(Prompt::ENTER_ACCOUNT_NUMBER);
    std::string accountNumber = _utility->getValidString();
    if(_bank->closeAccountAndDeleteUser(accountNumber)) {
        _logger->printInline(Success::ACCOUNT_CLOSED);
    }
    else {
        _logger->printError(Error::ACCOUNT_NOT_FOUND);
    }
}

void Application::displayAccountInfo(Account* account) {
    _logger->printInline("\nAccount Number: " + account->getAccountNumber() + "\n");
    _logger->printInline("Balance: Rs. " + std::to_string(account->getBalance()) + "\n");
    _logger->printInline("Status: " + std::string(account->isActive() ? "Active" : "Closed") + "\n");
    _logger->printInline("Frozen: " + std::string(account->isFrozen() ? "Yes" : "No") + "\n");
    _logger->printInline("Created: " + account->getCreatedDate() + "\n");
}

void Application::displayTransactions(std::vector<Transaction*> transactions) {
    if (transactions.empty()) {
        _logger->printInline(Error::NO_TRANSACTIONS);
        return;
    }
    
    for (Transaction* transaction : transactions) {
        std::cout << transaction->toString() << '\n';
    }
}
