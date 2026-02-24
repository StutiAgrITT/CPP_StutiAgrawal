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

        std::vector<std::string> columnNames = doc.GetColumnNames();
        if (columnNames.size() != Constants::NUM_FIELDS) {
            throw ParseException(Error::FIELD_COUNT_MISMATCH + std::to_string(Constants::NUM_FIELDS) + Error::BUT_GOT + std::to_string(columnNames.size()));
        }
        for (int fieldIndex = 0; fieldIndex < Constants::NUM_FIELDS; fieldIndex++) {
            if (columnNames[fieldIndex] != Constants::FIELDS[fieldIndex]) {
                throw ParseException(Error::FIELD_MISMATCH + Constants::FIELDS[fieldIndex] + Error::BUT_GOT + columnNames[fieldIndex]);
            }
        }
        clearRecords();

        for (int index = 0; index < doc.GetRowCount(); index++) {
            std::map<std::string, std::string> record;
            for (auto field : Constants::FIELDS) {
                try {
                    record[field] = doc.GetCell<std::string>(field, index);
                }
                catch (const std::exception&) {
                    throw ParseException(Error::MISSING_FIELD + field + Error::IN_ROW + std::to_string(index + 1));
                }
            }
            _records.push_back(record);
        }
    }
    catch (const ParseException&) {
        throw;
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
