#ifndef CSV_PARSER_H
#define CSV_PARSER_H

#include "Parser.h"

class CSVParser : public Parser {
public:
    CSVParser();
    ~CSVParser();

    void parse(const std::string& filePath) override;
    void save(const std::string& filePath) override;
};

#endif
