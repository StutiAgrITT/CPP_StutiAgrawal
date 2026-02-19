#include <iostream>
#include <vector>
#include <dirent.h>

std::vector<std::string> listFiles(const std::string& directory) {
    std::vector<std::string> files;
    
    DIR* dir = opendir(directory.c_str());
    if (!dir) {
        return files;
    }
    
    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        std::string filename = entry->d_name;
        files.push_back(filename);
    }
    closedir(dir);    
    return files;
}

int main() {
    std::vector<std::string> files = listFiles("./");
    for (std::string file : files) {
        std::cout << file << '\n';
    }
    return 0;
}