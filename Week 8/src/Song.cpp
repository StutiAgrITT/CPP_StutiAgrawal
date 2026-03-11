#include "Song.h"

Song::Song(const std::string& title, const std::string& filePath)
    : _title(title), _filePath(filePath) {}

std::string Song::getTitle() const { return _title;    }
std::string Song::getFilePath() const { return _filePath; }

bool Song::operator==(const Song& other) const {
    return _filePath == other._filePath;
}
