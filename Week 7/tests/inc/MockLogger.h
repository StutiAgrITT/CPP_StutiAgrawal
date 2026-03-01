#ifndef MOCK_LOGGER_H
#define MOCK_LOGGER_H

#include <gmock/gmock.h>
#include "ILogger.h"

class MockLogger : public ILogger {
public:
    MOCK_METHOD(void, printError, (const std::string& errorMsg), (override));
    MOCK_METHOD(void, printInline, (const std::string& message), (override));
};

#endif
