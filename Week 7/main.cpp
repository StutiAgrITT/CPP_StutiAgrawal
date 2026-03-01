#include "Application.h"
#include "Logger.h"
#include "Utility.h"
#include "Bank.h"

int main() {
    ILogger* logger = new Logger();
    IUtility* utility = new Utility(logger);
    IBank* bank = new Bank(logger, utility);

    Application app(bank, logger, utility);
    app.run();

    delete bank;
    delete utility;
    delete logger;
    return 0;
}