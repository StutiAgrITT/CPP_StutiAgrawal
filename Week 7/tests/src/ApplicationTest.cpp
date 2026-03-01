#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Application.h"
#include "MockBank.h"
#include "MockLogger.h"
#include "MockUtility.h"
#include "AccountHolder.h"
#include "Admin.h"
#include "Constants.h"

using ::testing::_;

class TestableApplication : public Application {
public:
    TestableApplication(IBank* bank, ILogger* logger, IUtility* utility)
        : Application(bank, logger, utility) {}

    using Application::handleLogin;
    using Application::handleSignup;
    using Application::handleLogout;
    using Application::handleDeposit;
    using Application::handleWithdraw;
    using Application::handleCheckBalance;
    using Application::handleMiniStatement;
    using Application::handleBankStatement;
    using Application::handleFreezeAccount;
    using Application::handleUnfreezeAccount;
    using Application::handleCloseAccountAndDeleteUser;
    using Application::setCurrentUser;
};

class ApplicationTest : public ::testing::Test {
protected:
    ::testing::NiceMock<MockBank>* mockBank;
    ::testing::NiceMock<MockLogger>* mockLogger;
    ::testing::NiceMock<MockUtility>* mockUtility;
    TestableApplication* app;

    AccountHolder* fakeUser;
    Account* fakeAccount;

    void SetUp() override {
        mockBank = new ::testing::NiceMock<MockBank>();
        mockLogger = new ::testing::NiceMock<MockLogger>();
        mockUtility = new ::testing::NiceMock<MockUtility>();
        app = new TestableApplication(mockBank, mockLogger, mockUtility);

        fakeUser = new AccountHolder("USR1","Stuti Agrawal","stuti@gmail.com","9876543210","Password@1");
        fakeAccount = new Account("ACC1001","USR1",500.0,mockUtility);
        fakeUser->setAccountId("ACC1001");
    }

    void TearDown() override {
        delete app;
        delete fakeUser;
        delete fakeAccount;
        delete mockBank;
        delete mockLogger;
        delete mockUtility;
    }

    void setFakeUserAsCurrentUser() {
        app->setCurrentUser(fakeUser);
    }
};

TEST_F(ApplicationTest, LoginSuccess_CallsBankLoginWithCorrectCredentials) {
    ON_CALL(*mockUtility,getValidString())
        .WillByDefault(::testing::Return("stuti@gmail.com"));
    ON_CALL(*mockUtility,getPassword())
        .WillByDefault(::testing::Return("Password@1"));
    ON_CALL(*mockUtility,getValidInteger())
        .WillByDefault(::testing::Return(6));
    EXPECT_CALL(*mockBank,login("stuti@gmail.com","Password@1")).WillOnce(::testing::Return(fakeUser));
    app->handleLogin();
}

TEST_F(ApplicationTest, LoginSuccess_PrintsWelcomeMessage) {
    ON_CALL(*mockUtility,getValidString())
        .WillByDefault(::testing::Return("stuti@gmail.com"));
    ON_CALL(*mockUtility,getPassword())
        .WillByDefault(::testing::Return("Password@1"));
    ON_CALL(*mockBank,login("stuti@gmail.com","Password@1"))
        .WillByDefault(::testing::Return(fakeUser));
    ON_CALL(*mockUtility,getValidInteger())
        .WillByDefault(::testing::Return(6));
    EXPECT_CALL(*mockLogger,printInline(_)).Times(::testing::AnyNumber());
    EXPECT_CALL(*mockLogger,printInline(Success::LOGIN + "Stuti Agrawal" + "!\n")).Times(1);
    app->handleLogin();
}

TEST_F(ApplicationTest, LoginFailure_PrintsErrorMessage) {
    ON_CALL(*mockUtility,getValidString())
        .WillByDefault(::testing::Return("stuti@gmail.com"));
    ON_CALL(*mockUtility,getPassword())
        .WillByDefault(::testing::Return("wrongpassword"));
    ON_CALL(*mockBank,login("stuti@gmail.com","wrongpassword"))
        .WillByDefault(::testing::Return(nullptr));
    EXPECT_CALL(*mockLogger,printError(Error::INVALID_CREDENTIALS)).Times(1);
    app->handleLogin();
}

TEST_F(ApplicationTest, LoginFailure_CallsBankLoginOnce) {
    ON_CALL(*mockUtility,getValidString())
        .WillByDefault(::testing::Return("wrong@gmail.com"));
    ON_CALL(*mockUtility,getPassword())
        .WillByDefault(::testing::Return("wrongpassword"));
    EXPECT_CALL(*mockBank,login("wrong@gmail.com","wrongpassword")).Times(1).WillOnce(::testing::Return(nullptr));
    app->handleLogin();
}

TEST_F(ApplicationTest, SignupSuccess_PrintsSuccessMessage) {
    ON_CALL(*mockUtility,getValidInteger())
        .WillByDefault(::testing::Return(1));
    ON_CALL(*mockUtility,getValidName())
        .WillByDefault(::testing::Return("Stuti Agrawal"));
    ON_CALL(*mockUtility,getValidEmail())
        .WillByDefault(::testing::Return("stuti@gmail.com"));
    ON_CALL(*mockUtility,getValidPhone())
        .WillByDefault(::testing::Return("9876543210"));
    ON_CALL(*mockUtility,getPassword())
        .WillByDefault(::testing::Return("Password@1"));
    ON_CALL(*mockUtility,getValidPositiveDouble())
        .WillByDefault(::testing::Return(500.0));
    ON_CALL(*mockBank,emailExists("stuti@gmail.com"))
        .WillByDefault(::testing::Return(false));
    ON_CALL(*mockBank,signup(_,_,_,_,_,_))
        .WillByDefault(::testing::Return(fakeUser));
    EXPECT_CALL(*mockLogger,printInline(_)).Times(::testing::AnyNumber());
    EXPECT_CALL(*mockLogger,printInline(Success::SIGNUP)).Times(1);
    app->handleSignup();
}

TEST_F(ApplicationTest, SignupFailure_DuplicateEmail_PrintsError) {
    ON_CALL(*mockUtility,getValidInteger())
        .WillByDefault(::testing::Return(1));
    ON_CALL(*mockUtility,getValidName())
        .WillByDefault(::testing::Return("Stuti Agrawal"));
    ON_CALL(*mockUtility,getValidEmail())
        .WillByDefault(::testing::Return("stuti@gmail.com"));
    ON_CALL(*mockBank,emailExists("stuti@gmail.com"))
        .WillByDefault(::testing::Return(true));
    EXPECT_CALL(*mockLogger,printError(Error::EMAIL_ALREADY_EXISTS)).Times(1);
    app->handleSignup();
}

TEST_F(ApplicationTest, SignupCallsBankWithCorrectDetails) {
    ON_CALL(*mockUtility,getValidInteger())
        .WillByDefault(::testing::Return(1));
    ON_CALL(*mockUtility,getValidName())
        .WillByDefault(::testing::Return("Stuti Agrawal"));
    ON_CALL(*mockUtility,getValidEmail())
        .WillByDefault(::testing::Return("stuti@gmail.com"));
    ON_CALL(*mockUtility,getValidPhone())
        .WillByDefault(::testing::Return("9876543210"));
    ON_CALL(*mockUtility,getPassword())
        .WillByDefault(::testing::Return("Password@1"));
    ON_CALL(*mockUtility,getValidPositiveDouble())
        .WillByDefault(::testing::Return(500.0));
    ON_CALL(*mockBank,emailExists(_))
        .WillByDefault(::testing::Return(false));
    EXPECT_CALL(*mockBank,signup("Stuti Agrawal","stuti@gmail.com","9876543210","Password@1",ACCOUNT_HOLDER,500.0)).WillOnce(::testing::Return(fakeUser));
    app->handleSignup();
}

TEST_F(ApplicationTest, SignupBelowMinDeposit_PrintsError) {
    ON_CALL(*mockUtility,getValidInteger())
        .WillByDefault(::testing::Return(1));
    ON_CALL(*mockUtility,getValidName())
        .WillByDefault(::testing::Return("Stuti Agrawal"));
    ON_CALL(*mockUtility,getValidEmail())
        .WillByDefault(::testing::Return("stuti@gmail.com"));
    ON_CALL(*mockUtility,getValidPhone())
        .WillByDefault(::testing::Return("9876543210"));
    ON_CALL(*mockUtility,getPassword())
        .WillByDefault(::testing::Return("Password@1"));
    ON_CALL(*mockUtility,getValidPositiveDouble())
        .WillByDefault(::testing::Return(50.0));
    ON_CALL(*mockBank,emailExists(_))
        .WillByDefault(::testing::Return(false));
    EXPECT_CALL(*mockLogger,printError(Error::MINIMUM_DEPOSIT_REQUIRED)).Times(1);
    app->handleSignup();
}

TEST_F(ApplicationTest, DepositSuccess_PrintsSuccessMessage) {
    setFakeUserAsCurrentUser();
    ON_CALL(*mockBank,getAccount("ACC1001"))
        .WillByDefault(::testing::Return(fakeAccount));
    ON_CALL(*mockUtility,getValidPositiveDouble())
        .WillByDefault(::testing::Return(100.0));
    EXPECT_CALL(*mockLogger,printInline(_)).Times(::testing::AnyNumber());
    EXPECT_CALL(*mockLogger,printInline(Success::DEPOSIT)).Times(1);
    app->handleDeposit();
}

TEST_F(ApplicationTest, DepositOnFrozenAccount_PrintsError) {
    setFakeUserAsCurrentUser();
    fakeAccount->freeze();
    ON_CALL(*mockBank,getAccount("ACC1001"))
        .WillByDefault(::testing::Return(fakeAccount));
    EXPECT_CALL(*mockLogger,printError(Error::ACCOUNT_FROZEN)).Times(1);
    app->handleDeposit();
}

TEST_F(ApplicationTest, DepositOnInactiveAccount_PrintsError) {
    setFakeUserAsCurrentUser();
    fakeAccount->deactivate();
    ON_CALL(*mockBank,getAccount("ACC1001"))
        .WillByDefault(::testing::Return(fakeAccount));
    EXPECT_CALL(*mockLogger,printError(Error::ACCOUNT_INACTIVE)).Times(1);
    app->handleDeposit();
}

TEST_F(ApplicationTest, DepositAccountNotFound_PrintsError) {
    setFakeUserAsCurrentUser();
    ON_CALL(*mockBank,getAccount("ACC1001"))
        .WillByDefault(::testing::Return(nullptr));
    EXPECT_CALL(*mockLogger,printError(Error::ACCOUNT_NOT_FOUND)).Times(1);
    app->handleDeposit();
}

TEST_F(ApplicationTest, WithdrawSuccess_PrintsSuccessMessage) {
    setFakeUserAsCurrentUser();
    ON_CALL(*mockBank,getAccount("ACC1001"))
        .WillByDefault(::testing::Return(fakeAccount));
    ON_CALL(*mockUtility,getValidPositiveDouble())
        .WillByDefault(::testing::Return(100.0));
    EXPECT_CALL(*mockLogger,printInline(_)).Times(::testing::AnyNumber());
    EXPECT_CALL(*mockLogger,printInline(Success::WITHDRAWAL)).Times(1);
    app->handleWithdraw();
}

TEST_F(ApplicationTest, WithdrawInsufficientBalance_PrintsError) {
    setFakeUserAsCurrentUser();
    ON_CALL(*mockBank,getAccount("ACC1001"))
        .WillByDefault(::testing::Return(fakeAccount));
    ON_CALL(*mockUtility,getValidPositiveDouble())
        .WillByDefault(::testing::Return(9999.0));
    EXPECT_CALL(*mockLogger,printError(Error::INSUFFICIENT_BALANCE)).Times(1);
    app->handleWithdraw();
}

TEST_F(ApplicationTest, WithdrawOnFrozenAccount_PrintsError) {
    setFakeUserAsCurrentUser();
    fakeAccount->freeze();
    ON_CALL(*mockBank,getAccount("ACC1001"))
        .WillByDefault(::testing::Return(fakeAccount));
    EXPECT_CALL(*mockLogger,printError(Error::ACCOUNT_FROZEN)).Times(1);
    app->handleWithdraw();
}

TEST_F(ApplicationTest, CheckBalance_PrintsAccountNumber) {
    setFakeUserAsCurrentUser();
    ON_CALL(*mockBank,getAccount("ACC1001"))
        .WillByDefault(::testing::Return(fakeAccount));
    EXPECT_CALL(*mockLogger,printInline(_)).Times(::testing::AnyNumber());
    EXPECT_CALL(*mockLogger,printInline("\nAccount Number: ACC1001\n")).Times(1);
    app->handleCheckBalance();
}

TEST_F(ApplicationTest, CheckBalance_AccountNotFound_PrintsError) {
    setFakeUserAsCurrentUser();
    ON_CALL(*mockBank,getAccount("ACC1001"))
        .WillByDefault(::testing::Return(nullptr));
    EXPECT_CALL(*mockLogger,printError(Error::ACCOUNT_NOT_FOUND)).Times(1);
    app->handleCheckBalance();
}

TEST_F(ApplicationTest, FreezeAccount_Success_PrintsSuccessMessage) {
    ON_CALL(*mockUtility,getValidString())
        .WillByDefault(::testing::Return("ACC1001"));
    ON_CALL(*mockBank,freezeAccount("ACC1001"))
        .WillByDefault(::testing::Return(true));
    EXPECT_CALL(*mockLogger,printInline(_)).Times(::testing::AnyNumber());
    EXPECT_CALL(*mockLogger,printInline(Success::ACCOUNT_FROZEN)).Times(1);
    app->handleFreezeAccount();
}

TEST_F(ApplicationTest, FreezeAccount_NotFound_PrintsError) {
    ON_CALL(*mockUtility,getValidString())
        .WillByDefault(::testing::Return("ACC9999"));
    ON_CALL(*mockBank,freezeAccount("ACC9999"))
        .WillByDefault(::testing::Return(false));
    EXPECT_CALL(*mockLogger,printError(Error::ACCOUNT_NOT_FOUND)).Times(1);
    app->handleFreezeAccount();
}

TEST_F(ApplicationTest, FreezeAccount_CallsBankWithCorrectAccountNumber) {
    ON_CALL(*mockUtility,getValidString())
        .WillByDefault(::testing::Return("ACC1001"));
    EXPECT_CALL(*mockBank,freezeAccount("ACC1001")).Times(1).WillOnce(::testing::Return(true));
    app->handleFreezeAccount();
}

TEST_F(ApplicationTest, UnfreezeAccount_Success_PrintsSuccessMessage) {
    ON_CALL(*mockUtility,getValidString())
        .WillByDefault(::testing::Return("ACC1001"));
    ON_CALL(*mockBank,unfreezeAccount("ACC1001"))
        .WillByDefault(::testing::Return(true));
    EXPECT_CALL(*mockLogger,printInline(_)).Times(::testing::AnyNumber());
    EXPECT_CALL(*mockLogger,printInline(Success::ACCOUNT_UNFROZEN)).Times(1);
    app->handleUnfreezeAccount();
}

TEST_F(ApplicationTest, UnfreezeAccount_NotFound_PrintsError) {
    ON_CALL(*mockUtility,getValidString())
        .WillByDefault(::testing::Return("ACC9999"));
    ON_CALL(*mockBank,unfreezeAccount("ACC9999"))
        .WillByDefault(::testing::Return(false));
    EXPECT_CALL(*mockLogger,printError(Error::ACCOUNT_NOT_FOUND)).Times(1);
    app->handleUnfreezeAccount();
}

TEST_F(ApplicationTest, UnfreezeAccount_CallsBankWithCorrectAccountNumber) {
    ON_CALL(*mockUtility,getValidString())
        .WillByDefault(::testing::Return("ACC1001"));
    EXPECT_CALL(*mockBank,unfreezeAccount("ACC1001")).Times(1).WillOnce(::testing::Return(true));
    app->handleUnfreezeAccount();
}

TEST_F(ApplicationTest, CloseAccount_Success_PrintsSuccessMessage) {
    ON_CALL(*mockUtility,getValidString())
        .WillByDefault(::testing::Return("ACC1001"));
    ON_CALL(*mockBank,closeAccountAndDeleteUser("ACC1001"))
        .WillByDefault(::testing::Return(true));
    EXPECT_CALL(*mockLogger,printInline(_)).Times(::testing::AnyNumber());
    EXPECT_CALL(*mockLogger,printInline(Success::ACCOUNT_CLOSED)).Times(1);
    app->handleCloseAccountAndDeleteUser();
}

TEST_F(ApplicationTest, CloseAccount_NotFound_PrintsError) {
    ON_CALL(*mockUtility,getValidString())
        .WillByDefault(::testing::Return("ACC9999"));
    ON_CALL(*mockBank,closeAccountAndDeleteUser("ACC9999"))
        .WillByDefault(::testing::Return(false));
    EXPECT_CALL(*mockLogger,printError(Error::ACCOUNT_NOT_FOUND)).Times(1);
    app->handleCloseAccountAndDeleteUser();
}

TEST_F(ApplicationTest, CloseAccount_CallsBankWithCorrectAccountNumber) {
    ON_CALL(*mockUtility,getValidString())
        .WillByDefault(::testing::Return("ACC1001"));
    EXPECT_CALL(*mockBank,closeAccountAndDeleteUser("ACC1001")).Times(1).WillOnce(::testing::Return(true));
    app->handleCloseAccountAndDeleteUser();
}

TEST_F(ApplicationTest, Logout_PrintsLogoutMessage) {
    EXPECT_CALL(*mockLogger,printInline(Success::LOGOUT)).Times(1);
    app->handleLogout();
}
