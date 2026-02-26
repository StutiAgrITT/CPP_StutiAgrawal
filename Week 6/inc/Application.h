#ifndef APPLICATION_H
#define APPLICATION_H

#include "Parser.h"
#include "ParserManager.h"
#include "FileManager.h"
#include "Logger.h"
#include "Utility.h"
#include <string>

class Application {
private:
    ParserManager* _parserManager;
    FileManager* _fileManager;
    Logger* _logger;
    Utility* _utility;
    Parser* _currentParser;
    bool _isRunning;

    void showMainMenu();
    void handleCreateFile();
    void handleEditFile();
    void handleParseAndDisplay();
    void handleDeleteFile();

    void handleEditAddRecord();
    void handleEditUpdateRecord();
    void handleEditDeleteRecord();
    void handleEditSaveChanges(std::string filepath, bool& editing);

    std::string selectFile();
    std::map<std::string, std::string> getUserInputForRecord();

public:
    Application();
    ~Application();
    void run();
};

#endif
