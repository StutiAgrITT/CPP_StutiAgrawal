#include "Parser.h"
#include "Exceptions.h"
#include "Constants.h"

Parser::Parser() {
    _logger = Logger::getInstance();
    _utility = Utility::getInstance();
}

Parser::~Parser() = default;

void Parser::display() {
    if (_records.empty()) {
        _logger->printMessage(Info::NO_RECORDS);
        return;
    }

    _logger->printMessage(Info::SEPARATOR);
    for (int recordIndex = 0; recordIndex < _records.size(); recordIndex++) {
        _logger->printMessage(Info::RECORD_PREFIX + std::to_string(recordIndex + 1) + Constants::NEWLINE);
        _logger->printMessage(Info::NAME + _records[recordIndex][Constants::FIELDS[0]] + Constants::NEWLINE);
        _logger->printMessage(Info::AGE + _records[recordIndex][Constants::FIELDS[1]] + Constants::NEWLINE);
        _logger->printMessage(Info::GENDER + _records[recordIndex][Constants::FIELDS[2]] + Constants::NEWLINE);
        _logger->printMessage(Info::CITY + _records[recordIndex][Constants::FIELDS[3]] + Constants::NEWLINE);
    }
    _logger->printMessage(Info::SEPARATOR);
    _logger->printMessage(Info::TOTAL_RECORDS + std::to_string(_records.size()) + Constants::NEWLINE);
}

void Parser::create(const std::string& filePath) {
    _logger->printMessage(Prompt::ENTER_NUM_RECORDS);
    int numRecords = _utility->getValidInteger();
    if (numRecords <= 0) {
        _logger->printMessage(Error::INVALID_INPUT);
        return;
    }

    clearRecords();

    for (int recordIndex = 0; recordIndex < numRecords; recordIndex++) {
        _logger->printMessage(Constants::NEWLINE + Info::RECORD_PREFIX + std::to_string(recordIndex + 1) + Constants::NEWLINE);
        std::map<std::string, std::string> record;

        _logger->printMessage(Prompt::ENTER_NAME);
        record[Constants::FIELDS[0]] = _utility->getValidString();
        _logger->printMessage(Prompt::ENTER_AGE);
        record[Constants::FIELDS[1]] = std::to_string(_utility->getValidAge());
        _logger->printMessage(Prompt::ENTER_GENDER);
        record[Constants::FIELDS[2]] = std::string(1, _utility->getValidGender());
        _logger->printMessage(Prompt::ENTER_CITY);
        record[Constants::FIELDS[3]] = _utility->getValidString();

        _records.push_back(record);
    }
    save(filePath);
    _logger->printMessage(Success::FILE_CREATED);
}

void Parser::addRecord(std::map<std::string, std::string> record) {
    _records.push_back(record);
}

void Parser::updateRecord(int index, std::map<std::string, std::string> record) {
    if (index < 0 || index >= _records.size()) {
        throw ValidationException(Error::INVALID_INDEX);
    }
    _records[index] = record;
}

void Parser::deleteRecord(int index) {
    if (index < 0 || index >= _records.size()) {
        throw ValidationException(Error::INVALID_INDEX);
    }
    _records.erase(_records.begin() + index);
}

std::map<std::string, std::string> Parser::getRecord(int index) {
    if (index < 0 || index >= _records.size()) {
        throw ValidationException(Error::INVALID_INDEX);
    }
    return _records[index];
}

void Parser::clearRecords() {
    _records.clear();
}

int Parser::getRecordCount() const {
    return _records.size();
}
