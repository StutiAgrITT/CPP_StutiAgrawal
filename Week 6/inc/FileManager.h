#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "Enums.h"
#include <string>
#include <vector>

class FileManager {
private:
    FileManager();
    static FileManager* instance;

public:
    FileManager(const FileManager&) = delete;
    FileManager& operator=(const FileManager&) = delete;
    
    static FileManager* getInstance();

    std::vector<std::string> listFiles(const std::string& directory);
    bool fileExists(const std::string& filePath);
    bool deleteFile(const std::string& filePath);
    FileFormat detectFormat(const std::string& filePath);
    std::string getFileExtension(const std::string& filePath);
};

#endif
