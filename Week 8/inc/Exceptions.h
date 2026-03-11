#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

class PlaylistException : public std::exception {
private:
    std::string _message;
public:
    PlaylistException(const std::string& msg) : _message(msg) {}
    const char* what() const noexcept override { return _message.c_str(); }
};

class AudioException : public std::exception {
private:
    std::string _message;
public:
    AudioException(const std::string& msg) : _message(msg) {}
    const char* what() const noexcept override { return _message.c_str(); }
};

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

#endif
