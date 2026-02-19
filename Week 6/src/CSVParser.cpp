#include "CSVParser.h"
#include "Constants.h"
#include "Utility.h"
#include "Exceptions.h"
#include <fstream>
#include <iostream>
#include <sstream>

CSVParser::CSVParser() = default;
CSVParser::~CSVParser() = default;

void CSVParser::parse(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file) {
        throw FileException(Error::FILE_OPEN_FAILED);
    }

    clearRecords();
    std::string line;

    if (!std::getline(file, line)) {
        throw ParseException(Error::EMPTY_FILE);
    }

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::map<std::string, std::string> record;
        std::stringstream ss(line);
        std::string value;

        for (int field = 0; field < Constants::NUM_FIELDS; field++) {
            std::getline(ss, value, ',');
            record[Constants::FIELDS[field]] = value;
        }
        _records.push_back(record);
    }
    file.close();
}

void CSVParser::save(const std::string& filePath) {
    std::ofstream file(filePath);
    if (!file) {
        throw FileException(Error::FILE_WRITE_FAILED);
    }

    file << Constants::FIELDS[0] << Constants::COMMA
         << Constants::FIELDS[1] << Constants::COMMA
         << Constants::FIELDS[2] << Constants::COMMA
         << Constants::FIELDS[3] << Constants::NEWLINE;
    
    for (std::map<std::string, std::string> record : _records) {
        file << record[Constants::FIELDS[0]] << Constants::COMMA
             << stoi(record[Constants::FIELDS[1]]) << Constants::COMMA
             << record[Constants::FIELDS[2]] << Constants::COMMA
             << record[Constants::FIELDS[3]] << Constants::NEWLINE;
    }
    file.close();
}
