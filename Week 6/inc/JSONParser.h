#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include "Parser.h"
#include "json.hpp"

class JSONParser : public Parser {
public:
    JSONParser();
    ~JSONParser();

    void parse(const std::string& filePath) override;
    void save(const std::string& filePath) override;
};

#endif
