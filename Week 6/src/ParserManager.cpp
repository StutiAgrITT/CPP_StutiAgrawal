#include "ParserManager.h"
#include "Utility.h"
#include "Logger.h"
#include "Constants.h"
#include "JSONParser.h"
#include "CSVParser.h"
#include "XMLParser.h"

ParserManager* ParserManager::instance = nullptr;

ParserManager::ParserManager() {
    _logger = Logger::getInstance();
    _utility = Utility::getInstance();
}

ParserManager* ParserManager::getInstance() {
    if (instance == nullptr) {
        instance = new ParserManager();
    }
    return instance;
}

Parser* ParserManager::getParser(FileFormat format) {
    switch (format) {
    case JSON:
        return new JSONParser();
    case CSV:
        return new CSVParser();
    case XML:
        return new XMLParser();
    default:
        return nullptr;
    }
}

std::string ParserManager::getFormatFromUser() {
    _logger->printMessage(Menu::SELECT_FORMAT);
    int choice = _utility->getValidInteger();

    switch (choice) {
        case JSON:
            return Extensions::JSON;
        case CSV:
            return Extensions::CSV;
        case XML:
            return Extensions::XML;
        default:
            _logger->printError(Error::INVALID_CHOICE);
            return getFormatFromUser();
    }
}
