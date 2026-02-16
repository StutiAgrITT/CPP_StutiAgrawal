#ifndef APPLICATION_H
#define APPLICATION_H

#include "Bank.h"
#include "Logger.h"
#include "Utility.h"
#include "User.h"
#include "AccountHolder.h"
#include "Admin.h"
#include "Account.h"

class Application {
private:
    Bank* _bank;
    Logger* _logger;
    Utility* _utility;
    User* _currentUser;
    bool _isRunning;

    void showLoginMenu();
    void handleSignup();
    void handleLogin();
    void handleLogout();

    void showAccountHolderMenu();
    void handleDeposit();
    void handleWithdraw();
    void handleCheckBalance();
    void handleMiniStatement();
    void handleBankStatement();

    void showAdminMenu();
    void handleViewAllUsersAndAccounts();
    void handleFreezeAccount();
    void handleUnfreezeAccount();
    void handleCloseAccountAndDeleteUser();

    void displayAccountInfo(Account* account);
    void displayTransactions(std::vector<Transaction*> transactions);

public:
    Application();
    ~Application();
    void run();
};

#endif