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
    void showAccountHolderMenu();
    void showAdminMenu();
    void displayAccountInfo(Account* account);
    void displayTransactions(std::vector<Transaction*> transactions);

protected:
    void handleSignup();
    void handleLogin();
    void handleLogout();
    void handleDeposit();
    void handleWithdraw();
    void handleCheckBalance();
    void handleMiniStatement();
    void handleBankStatement();
    void handleViewAllUsersAndAccounts();
    void handleFreezeAccount();
    void handleUnfreezeAccount();
    void handleCloseAccountAndDeleteUser();
    void setCurrentUser(User* user) { _currentUser = user; }
    
public:
    Application(IBank* bank, ILogger* logger, IUtility* utility);
    ~Application();
    void run();
};

#endif
