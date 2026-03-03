#ifndef MOCK_UTILITY_H
#define MOCK_UTILITY_H

#include <gmock/gmock.h>
#include "IUtility.h"

class MockUtility : public IUtility {
public:
    MOCK_METHOD(double, getValidDouble, (), (override));
    MOCK_METHOD(double, getValidPositiveDouble, (), (override));
    MOCK_METHOD(int, getValidInteger, (), (override));
    MOCK_METHOD(std::string, getValidString, (), (override));
    MOCK_METHOD(std::string, getValidName, (), (override));
    MOCK_METHOD(std::string, getValidEmail, (), (override));
    MOCK_METHOD(std::string, getValidPhone, (), (override));
    MOCK_METHOD(std::string, getPassword, (), (override));
    MOCK_METHOD(std::string, getCurrentDateTime, (), (override));
};

#endif
