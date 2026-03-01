#ifndef APPLICATION_H
#define APPLICATION_H

#include "IBank.h"
#include "ILogger.h"
#include "IUtility.h"
#include "User.h"
#include "AccountHolder.h"
#include "Admin.h"
#include "Account.h"

class Application {
private:
    IBank* _bank;
    ILogger* _logger;
    IUtility* _utility;
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
    Application(IBank* bank, ILogger* logger, IUtility* utility);
    ~Application();
    void run();
};

#endif
