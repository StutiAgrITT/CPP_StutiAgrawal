#include "CSVParser.h"
#include "Constants.h"
#include "Utility.h"
#include "Exceptions.h"
#include <fstream>
#include <iostream>

CSVParser::CSVParser() = default;
CSVParser::~CSVParser() = default;

void CSVParser::parse(const std::string& filePath) {
    try {
        rapidcsv::Document doc(filePath);
        clearRecords();

        for (int index = 0; index < doc.GetRowCount(); index++) {
            std::map<std::string, std::string> record;
            for (auto field : Constants::FIELDS) {
                record[field] = doc.GetCell<std::string>(field, index);
            }
            _records.push_back(record);
        }
    }
    catch (const std::exception&) {
        throw FileException(Error::FILE_OPEN_FAILED);
    }
}

void CSVParser::save(const std::string& filePath) {
    try {
        rapidcsv::Document doc;

        for (int index = 0; index < Constants::NUM_FIELDS; index++) {
            doc.SetColumnName(index, Constants::FIELDS[index]);
        }
        for (int index = 0; index < _records.size(); index++) {
            for (auto field : Constants::FIELDS) {
                doc.SetCell<std::string>(field, index, _records[index][field]);
            }
        }
        doc.Save(filePath);
    }
    catch (const std::exception&) {
        throw FileException(Error::FILE_WRITE_FAILED);
    }
}
