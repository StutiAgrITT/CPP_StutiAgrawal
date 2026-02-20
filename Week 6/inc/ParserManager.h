#include "Enums.h"
#include "Parser.h"
#include <string>

#ifndef PARSER_MANAGER_H
#define PARSER_MANAGER_H

class ParserManager {
private:
    ParserManager();
    static ParserManager* instance;
    Logger* _logger;
    Utility* _utility;

public:
    ParserManager(const ParserManager&) = delete;
    ParserManager& operator=(const ParserManager&) = delete;

    static ParserManager* getInstance();

    Parser* getParser(FileFormat format);
    std::string getFormatFromUser();
};

#endif
