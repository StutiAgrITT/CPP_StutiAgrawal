#ifndef SONG_H
#define SONG_H

#include <string>

class Song {
private:
    std::string _title;
    std::string _filePath;

public:
    Song(const std::string& title, const std::string& filePath);

    std::string getTitle() const;
    std::string getFilePath() const;

    bool operator==(const Song& other) const;
};

#endif
