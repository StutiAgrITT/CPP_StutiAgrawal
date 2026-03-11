#ifndef MOCK_UTILITY_H
#define MOCK_UTILITY_H

#include <gmock/gmock.h>
#include "IUtility.h"

class MockUtility : public IUtility {
public:
    MOCK_METHOD(int, getValidInteger, (), (override));
    MOCK_METHOD(std::string, getValidString, (), (override));
    MOCK_METHOD(std::string, getValidFilename, (), (override));
};

#endif