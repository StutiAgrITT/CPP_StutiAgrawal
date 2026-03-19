#ifndef IFILE_HANDLER_H
#define IFILE_HANDLER_H

#include <string>

class IFileHandler {
public:
    virtual ~IFileHandler() = default;
    virtual void save(const std::string& path) = 0;
    virtual void load(const std::string& path) = 0;
};

#endif
