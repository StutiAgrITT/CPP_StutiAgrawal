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
            break;
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
    FileFormat format = _fileManager->detectFormat(extension);
    if(_currentParser) delete _currentParser;
    _currentParser = _parserManager->getParser(format);
    _currentParser->create(filePath);
}

void Application::handleEditFile() {
    std::string filePath = selectFile();
    if (filePath.empty()) {
        return;
    }
    FileFormat format = _fileManager->detectFormat(filePath);
    if (_currentParser) delete _currentParser;
    _currentParser = _parserManager->getParser(format);

    _currentParser->parse(filePath);

    bool editing = true;

    _logger->printMessage(Info::CURRENT_DATA);
    _currentParser->display();

    while (editing) {
        _logger->printMessage(Menu::EDIT);
        int choice = _utility->getValidInteger();

        switch (choice) {
        case 1:
            handleEditAddRecord();
            break;
        
        case 2:
            handleEditUpdateRecord();
            break;
    
        case 3:
            handleEditDeleteRecord();
            break;

        case 4:
            handleEditSaveChanges(filePath, editing);
            break;

        case 5:
            editing = false;
            break;

        default:
            _logger->printError(Error::INVALID_CHOICE);
        }
    }
}

void Application::handleEditAddRecord() {
    std::map<std::string, std::string> record = getUserInputForRecord();
    _currentParser->addRecord(record);
    _logger->printMessage(Success::RECORD_ADDED);
}

void Application::handleEditUpdateRecord() {
    if (_currentParser->getRecordCount() == 0) {
        _logger->printError(Info::NO_RECORDS);
        return;
    }
    _logger->printMessage(Prompt::SELECT_RECORD);
    int index = _utility->getValidInteger() - 1;

    std::map<std::string, std::string> record = getUserInputForRecord();
    _currentParser->updateRecord(index, record);
    _logger->printMessage(Success::RECORD_UPDATED);
}

void Application::handleEditDeleteRecord() {
    if (_currentParser->getRecordCount() == 0) {
        _logger->printError(Info::NO_RECORDS);
        return;
    }
    _logger->printMessage(Prompt::SELECT_RECORD);
    int index = _utility->getValidInteger() - 1;

    _currentParser->deleteRecord(index);
    _logger->printMessage(Success::RECORD_DELETED);
}

void Application::handleEditSaveChanges(std::string filePath, bool& editing) {
    _currentParser->save(filePath);
    _logger->printMessage(Success::FILE_SAVED);
    editing = false;
}

void Application::handleParseAndDisplay() {
    std::string filePath = selectFile();
    if (filePath.empty()) return;

    FileFormat format = _fileManager->detectFormat(filePath);

    if (_currentParser) delete _currentParser;
    _currentParser = _parserManager->getParser(format);
    _currentParser->parse(filePath);
    _logger->printMessage(Info::PARSED_DATA_HEADER + filePath + Constants::NEWLINE);
    _currentParser->display();
    _logger->printMessage(Success::FILE_PARSED);
}

void Application::handleDeleteFile() {
    std::string filePath = selectFile();
    if (filePath.empty()) return;

    if (_fileManager->deleteFile(filePath)) {
        _logger->printMessage(Success::FILE_DELETED);
    }
    else {
        _logger->printError(Error::FILE_NOT_FOUND);
    }
}

std::string Application::selectFile() {
    std::vector<std::string> files = _fileManager->listFiles(Path::DATA_DIR);

    if (files.empty()) {
        _logger->printError(Error::NO_FILES);
        return Constants::EMPTY;
    }
    _logger->printMessage(Info::AVAILABLE_FILES);

    for (int fileIndex = 0; fileIndex < files.size(); fileIndex++) {
        _logger->printMessage(std::to_string(fileIndex + 1) + ". " + files[fileIndex] + Constants::NEWLINE);
    }

    _logger->printMessage(Prompt::SELECT_FILE);
    int choice = _utility->getValidInteger();

    if (choice <= 0 || choice > files.size()) {
        _logger->printError(Error::INVALID_INDEX);
        return Constants::EMPTY;
    }
    return Path::DATA_DIR + files[choice - 1];
}

std::map<std::string, std::string> Application::getUserInputForRecord() {
    std::map<std::string, std::string> record;

    _logger->printMessage(Prompt::ENTER_NAME);
    record[Constants::FIELDS[0]] = _utility->getValidString();

    _logger->printMessage(Prompt::ENTER_AGE);
    record[Constants::FIELDS[1]] = std::to_string(_utility->getValidAge());

    _logger->printMessage(Prompt::ENTER_GENDER);
    record[Constants::FIELDS[2]] = std::string(1, _utility->getValidGender());

    _logger->printMessage(Prompt::ENTER_CITY);
    record[Constants::FIELDS[3]] = _utility->getValidString();

    return record;
}
