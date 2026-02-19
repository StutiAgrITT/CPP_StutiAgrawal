#include "FileManager.h"
#include "Constants.h"
#include "Exceptions.h"
#include <fstream>
#include <dirent.h>

FileManager* FileManager::instance = nullptr;

FileManager::FileManager() = default;

FileManager* FileManager::getInstance() {
    if (instance == nullptr) {
        instance = new FileManager();
    }
    return instance;
}

std::vector<std::string> FileManager::listFiles(const std::string& directory) {
    std::vector<std::string> files;
    
    DIR* dir = opendir(directory.c_str());
    if (!dir) {
        return files;
    }
    
    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        std::string filename = entry->d_name;
        
        if (filename == "." || filename == "..") {
            continue;
        }
        
        std::string extension = getFileExtension(filename);
        if (extension == Extensions::JSON || extension == Extensions::CSV || extension == Extensions::XML) {
            files.push_back(filename);
        }
    }
    
    closedir(dir);    
    return files;
}

bool FileManager::fileExists(const std::string& filePath) {
    std::ifstream file(filePath);
    return (bool)file;
}

bool FileManager::deleteFile(const std::string& filePath) {
    return remove(filePath.c_str()) == 0;
}

FileFormat FileManager::detectFormat(const std::string& filePath) {
    std::string extension = getFileExtension(filePath);
    
    if (extension == Extensions::JSON) {
        return JSON;
    }
    else if (extension == Extensions::CSV) {
        return CSV;
    }
    else if (extension == Extensions::XML) {
        return XML;
    }
    throw ValidationException(Error::INVALID_FORMAT);
}

std::string FileManager::getFileExtension(const std::string& filePath) {
    int dotPosition = filePath.find_last_of('.');
    
    if (dotPosition == -1) {
        return Constants::EMPTY;
    }
    
    return filePath.substr(dotPosition);
}
