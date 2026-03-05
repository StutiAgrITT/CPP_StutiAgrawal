#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Song.h"
#include <string>
#include <vector>

class Playlist {
private:
    std::string _name;
    std::vector<Song> _songs;
    int _currentIndex;

public:
    Playlist(const std::string& name);

    void addSong(const Song& song);
    bool removeSong(int index);
    bool moveSongUp(int index);
    bool moveSongDown(int index);

    bool next();
    bool previous();

    Song* getCurrentSong();
    int getCurrentIndex() const;
    const std::vector<Song>& getSongs() const;
    std::string getName() const;
    int getSongCount() const;
    bool hasSongs() const;
    bool hasSong(const Song& song) const;
    void clearSongs();
    void setCurrentIndex(int index);
};

#endif
