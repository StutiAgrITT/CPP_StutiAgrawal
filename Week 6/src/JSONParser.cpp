#include "JSONParser.h"
#include "Constants.h"
#include "Utility.h"
#include "Exceptions.h"
#include <fstream>
#include <iostream>

JSONParser::JSONParser() = default;
JSONParser::~JSONParser() = default;

void JSONParser::parse(const std::string& filePath) {
    try {
        std::ifstream file(filePath);
        if (!file) {
            throw FileException(Error::FILE_OPEN_FAILED);
        }
        nlohmann::json data;
        file >> data;
        file.close();

        if (!data.contains(Constants::JSON_KEY) || !data[Constants::JSON_KEY].is_array()) {
            throw ParseException(Error::PARSE_FAILED);
        }

        clearRecords();

        for (nlohmann::json record : data[Constants::JSON_KEY]) {
            std::map<std::string, std::string> map;
            map[Constants::FIELDS[0]] = record[Constants::FIELDS[0]];
            map[Constants::FIELDS[1]] = std::to_string((int)record[Constants::FIELDS[1]]);
            map[Constants::FIELDS[2]] = record[Constants::FIELDS[2]];
            map[Constants::FIELDS[3]] = record[Constants::FIELDS[3]];

            _records.push_back(map);
        }
    }
    catch (nlohmann::json::exception& e) {
        throw ParseException(Error::PARSE_FAILED);
    }
}

void JSONParser::save(const std::string& filePath) {
    nlohmann::json data;
    data[Constants::JSON_KEY] = nlohmann::json::array();

    for (std::map<std::string, std::string> record : _records) {
        nlohmann::json jsonRecord;
        jsonRecord[Constants::FIELDS[0]] = record[Constants::FIELDS[0]];
        jsonRecord[Constants::FIELDS[1]] = std::stoi(record[Constants::FIELDS[1]]);
        jsonRecord[Constants::FIELDS[2]] = record[Constants::FIELDS[2]];
        jsonRecord[Constants::FIELDS[3]] = record[Constants::FIELDS[3]];
        data[Constants::JSON_KEY].push_back(jsonRecord);
    }

    std::ofstream file(filePath);
    if (!file) {
        throw FileException(Error::FILE_WRITE_FAILED);
    }

    file << data.dump(4);
    file.close();
}
