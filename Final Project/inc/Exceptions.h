#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

class FileException : public std::exception {
private:
    std::string _message;
public:
    FileException(const std::string& msg) : _message(msg) {}
    const char* what() const noexcept override { return _message.c_str(); }
};

class ValidationException : public std::exception {
private:
    std::string _message;
public:
    ValidationException(const std::string& msg) : _message(msg) {}
    const char* what() const noexcept override { return _message.c_str(); }
};

class AuthException : public std::exception {
private:
    std::string _message;
public:
    AuthException(const std::string& msg) : _message(msg) {}
    const char* what() const noexcept override { return _message.c_str(); }
};

#endif
