#include "Enums.h"
#include "Parser.h"

#ifndef PARSER_MANAGER_H
#define PARSER_MANAGER_H

class ParserManager {
private:
    ParserManager();
    static ParserManager* instance;

public:
    ParserManager(const ParserManager&) = delete;
    ParserManager& operator=(const ParserManager&) = delete;

    static ParserManager* getInstance();

    void getParser(FileFormat format);
    FileFormat getFormatFromUser();
};

#endif
