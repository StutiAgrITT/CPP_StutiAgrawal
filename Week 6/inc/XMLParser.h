#ifndef XML_PARSER_H
#define XML_PARSER_H

#include "Parser.h"

class XMLParser : public Parser {
public:
    XMLParser();
    ~XMLParser();

    void parse(const std::string& filePath) override;
    void save(const std::string& filePath) override;
};

#endif
