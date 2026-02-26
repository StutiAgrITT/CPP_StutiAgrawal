#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

class FileException : public std::exception {
private:
    std::string _message;
    
public:
    FileException(std::string msg) : _message(msg) {}
    const char* what() const noexcept override {
        return _message.c_str();
    }
};

class ParseException : public std::exception {
private:
    std::string _message;

public:
    ParseException(std::string msg) : _message(msg) {}
    const char* what() const noexcept override {
        return _message.c_str();
    }
};

class ValidationException : public std::exception {
private:
    std::string _message;

public:
    ValidationException(std::string msg) : _message(msg) {}
    const char* what() const noexcept override {
        return _message.c_str();
    }
};

#endif
