#ifndef PLAYLIST_MANAGER_H
#define PLAYLIST_MANAGER_H

#include "Playlist.h"
#include "Song.h"
#include "ILogger.h"
#include <string>
#include <map>
#include <vector>

class PlaylistManager {
private:
    std::map<std::string, Playlist> _playlists;
    std::vector<Song> _songLibrary;
    ILogger* _logger;

public:
    PlaylistManager(ILogger* logger);
    ~PlaylistManager() = default;

    void loadLibrary(const std::string& songsDir);
    const std::vector<Song>& getSongLibrary() const;

    bool createPlaylist(const std::string& name);
    bool deletePlaylist(const std::string& name);
    Playlist* getPlaylist(const std::string& name);
    bool playlistExists(const std::string& name) const;

    const std::map<std::string, Playlist>& getPlaylists() const;

    void savePlaylist(const std::string& name);
    void loadPlaylist(const std::string& name);
    void loadAllPlaylists();
};

#endif
