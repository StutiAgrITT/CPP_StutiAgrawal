#include "PlaylistManager.h"
#include "Constants.h"
#include "Exceptions.h"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <dirent.h>

PlaylistManager::PlaylistManager(ILogger* logger) : _logger(logger) {}

void PlaylistManager::loadLibrary(const std::string& songsDir) {
    _songLibrary.clear();

    DIR* dir = opendir(songsDir.c_str());
    if (!dir) return;

    std::vector<std::string> filenames;
    struct dirent* entry;

    while ((entry = readdir(dir)) != nullptr) {
        std::string filename = entry->d_name;

        if (filename.size() > 4 &&
            filename.substr(filename.size() - 4) == Extensions::OGG) {
            filenames.push_back(filename);
        }
    }
    closedir(dir);

    std::sort(filenames.begin(), filenames.end());

    std::transform(filenames.begin(), filenames.end(),
                   std::back_inserter(_songLibrary),
                   [&songsDir](const std::string& filename) {
                       std::string title = filename.substr(0, filename.size() - 4);
                       return Song(title, songsDir + filename);
                   });
}

const std::vector<Song>& PlaylistManager::getSongLibrary() const {
    return _songLibrary;
}

bool PlaylistManager::createPlaylist(const std::string& name) {
    if (playlistExists(name)) return false;
    _playlists.emplace(name, Playlist(name));
    return true;
}

bool PlaylistManager::deletePlaylist(const std::string& name) {
    auto it = _playlists.find(name);
    if (it == _playlists.end()) return false;
    _playlists.erase(it);

    std::string filePath = Path::DATA_DIR + name + Extensions::TXT;
    std::remove(filePath.c_str());
    return true;
}

Playlist* PlaylistManager::getPlaylist(const std::string& name) {
    auto it = _playlists.find(name);
    if (it == _playlists.end()) return nullptr;
    return &it->second;
}

bool PlaylistManager::playlistExists(const std::string& name) const {
    return _playlists.find(name) != _playlists.end();
}

const std::map<std::string, Playlist>& PlaylistManager::getPlaylists() const {
    return _playlists;
}

void PlaylistManager::savePlaylist(const std::string& name) {
    Playlist* playlist = getPlaylist(name);
    if (!playlist) throw FileException(Error::PLAYLIST_NOT_FOUND);

    std::string filePath = Path::DATA_DIR + name + Extensions::TXT;
    std::ofstream file(filePath);
    if (!file) throw FileException(Error::FILE_WRITE_FAILED);

    for (const Song& song : playlist->getSongs()) {
        std::string path = song.getFilePath();
        size_t lastSlash = path.find_last_of('/');
        std::string filename = (lastSlash != std::string::npos)
                               ? path.substr(lastSlash + 1)
                               : path;
        file << filename << "\n";
    }
    file.close();
}

void PlaylistManager::loadPlaylist(const std::string& name) {
    std::string filePath = Path::DATA_DIR + name + Extensions::TXT;
    std::ifstream file(filePath);
    if (!file) throw FileException(Error::FILE_OPEN_FAILED);

    if (!playlistExists(name)) {
        _playlists.emplace(name, Playlist(name));
    }

    Playlist* playlist = getPlaylist(name);
    std::string filename;

    while (std::getline(file, filename)) {
        if (filename.empty()) continue;

        auto it = std::find_if(_songLibrary.begin(), _songLibrary.end(),
                               [&filename](const Song& song) {
                                   std::string path = song.getFilePath();
                                   size_t lastSlash = path.find_last_of('/');
                                   std::string libFilename = (lastSlash != std::string::npos)
                                                             ? path.substr(lastSlash + 1)
                                                             : path;
                                   return libFilename == filename;
                               });

        if (it != _songLibrary.end()) {
            playlist->addSong(*it);
        }
    }
    file.close();
}

void PlaylistManager::loadAllPlaylists() {
    DIR* dir = opendir(Path::DATA_DIR.c_str());
    if (!dir) return;

    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        std::string filename = entry->d_name;

        if (filename.size() > 4 &&
            filename.substr(filename.size() - 4) == Extensions::TXT) {
            std::string name = filename.substr(0, filename.size() - 4);
            try {
                loadPlaylist(name);
            } catch (...) {
            }
        }
    }
    closedir(dir);
}
