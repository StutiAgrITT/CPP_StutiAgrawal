#ifndef PARSER_H
#define PARSER_H

#include "Logger.h"
#include "Utility.h"
#include <string>
#include <map>
#include <vector>

class Parser {
protected:
    std::vector<std::map<std::string, std::string>> _records;
    Logger* _logger;
    Utility* _utility;

public:
    Parser();
    virtual ~Parser();

    virtual void parse(const std::string& filePath) = 0;
    virtual void save(const std::string& filePath) = 0;

    void display();
    void create(const std::string& filePath);

    void addRecord(std::map<std::string, std::string> record);
    void updateRecord(int index, std::map<std::string, std::string> record);
    void deleteRecord(int index);
    std::map<std::string, std::string> getRecord(int index);

    void clearRecords();
    int getRecordCount() const;
};

#endif
