#include "Application.h"
#include "Constants.h"
#include "Exceptions.h"
#include <iostream>

Application::Application() {
    _parserManager = ParserManager::getInstance();
    _fileManager = FileManager::getInstance();
    _logger = Logger::getInstance();
    _utility = Utility::getInstance();
    _currentParser = nullptr;
    _isRunning = true;
}

Application::~Application() {
    if (_currentParser) {
        delete _currentParser;
    }
}

void Application::run() {
    _logger->printMessage(Info::WELCOME);
    while (_isRunning) {
        showMainMenu();
    }
}

void Application::showMainMenu() {
    _logger->printMessage(Menu::MAIN);
    int choice = _utility->getValidInteger();

    try {
        switch (choice) {
        case 1:
            handleCreateFile();
            break;
        case 2:
            handleEditFile();
            break;
        case 3:
            handleParseAndDisplay();
            break;
        case 4:
            handleDeleteFile();
            break;
        case 5:
            _logger->printMessage(Info::GOODBYE);
            _isRunning = false;
        default:
            _logger->printError(Error::INVALID_CHOICE);
        }
    }
    catch (std::exception& exception) {
        _logger->printError(exception.what());
    }
}

void Application::handleCreateFile() {
    _logger->printMessage(Prompt::ENTER_FILENAME);
    std::string filename = _utility->getValidFilename();
    std::string extension = _parserManager->getFormatFromUser();

    std::string filePath = Path::DATA_DIR + filename + extension;

    if (_fileManager->fileExists(filePath)) {
        _logger->printError(Error::FILE_ALREADY_EXISTS);
        return;
    }
    //_currentParser = _parserManager->getParser();
}