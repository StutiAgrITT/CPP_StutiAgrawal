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

    void showLoginMenu();
    void handleSignup();
    void handleLogin();
    void handleLogout();

    void showAccountHolderMenu();
    void handleCreateAccount();
    void handleDeposit();
    void handleWithdraw();
    void handleCheckBalance();
    void handleMiniStatement();
    void handleBankStatement();
    void handleCloseAccount();

    void showAdminMenu();
    void handleViewAllAccounts();
    void handleViewAllUsers();
    void handleFreezeAccount();
    void handleUnfreezeAccount();
    void handleDeleteAccount();

    void displayAccountInfo(Account* account);
    void displayTransactions(std::vector<Transaction*> transactions);

public:
    Application();
    ~Application();
    void run();
};

#endif