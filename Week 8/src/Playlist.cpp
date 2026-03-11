#include "Playlist.h"
#include "Exceptions.h"
#include <algorithm>

Playlist::Playlist(const std::string& name)
    : _name(name), _currentIndex(0) {}

void Playlist::addSong(const Song& song) {
    _songs.push_back(song);
}

bool Playlist::removeSong(int index) {
    if (index < 0 || index >= _songs.size()) {
        return false;
    }
    _songs.erase(_songs.begin() + index);

    if (_currentIndex >= _songs.size()) {
        _currentIndex = _songs.size() - 1;
    }
    if (_currentIndex < 0) {
        _currentIndex = 0;
    }
    return true;
}

bool Playlist::moveSongUp(int index) {
    if (index <= 0 || index >= _songs.size()) {
        return false;
    }
    auto it = _songs.begin() + index;
    std::iter_swap(it, it - 1);

    if (_currentIndex == index) _currentIndex--;
    else if (_currentIndex == index - 1) _currentIndex++;

    return true;
}

bool Playlist::moveSongDown(int index) {
    if (index < 0 || index >= _songs.size() - 1) {
        return false;
    }
    auto it = _songs.begin() + index;
    std::iter_swap(it, it + 1);

    if (_currentIndex == index) _currentIndex++;
    else if (_currentIndex == index + 1) _currentIndex--;

    return true;
}

bool Playlist::next() {
    if (_songs.empty()) return false;
    _currentIndex = (_currentIndex + 1) % _songs.size();
    return true;
}

bool Playlist::previous() {
    if (_songs.empty()) return false;
    _currentIndex = (_currentIndex - 1 + _songs.size()) % _songs.size();
    return true;
}

Song* Playlist::getCurrentSong() {
    if (_songs.empty() || _currentIndex < 0 || _currentIndex >= _songs.size()) {
        return nullptr;
    }
    return &_songs[_currentIndex];
}

int Playlist::getCurrentIndex() const {
    return _currentIndex;
}

const std::vector<Song>& Playlist::getSongs() const {
    return _songs;
}

std::string Playlist::getName() const {
    return _name;
}

int Playlist::getSongCount() const {
    return _songs.size();
}

bool Playlist::hasSongs() const {
    return !_songs.empty();
}

bool Playlist::hasSong(const Song& song) const {
    return std::find(_songs.begin(), _songs.end(), song) != _songs.end();
}

void Playlist::clearSongs() {
    _songs.clear();
    _currentIndex = 0;
}

void Playlist::setCurrentIndex(int index) {
    if (index >= 0 && index < _songs.size()) {
        _currentIndex = index;
    }
}
