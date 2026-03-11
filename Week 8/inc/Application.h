#ifndef APPLICATION_H
#define APPLICATION_H

#include "PlaylistManager.h"
#include "IAudioPlayer.h"
#include "ILogger.h"
#include "IUtility.h"
#include "Playlist.h"

class Application {
private:
    PlaylistManager* _manager;
    IAudioPlayer* _audioPlayer;
    ILogger* _logger;
    IUtility* _utility;
    bool _isRunning;
    Playlist* _currentPlaylist;

    void showMainMenu();
    void showPlaylistMenu();
    void showPlayerMenu();

    void handleCreatePlaylist();
    void handleDeletePlaylist();
    void handleSelectPlaylist();
    void handleViewAllPlaylists();

    void handleAddSong();
    void handleRemoveSong();
    void handleMoveSongUp();
    void handleMoveSongDown();

    void handlePlay();
    void handlePauseResume();
    void handleNext();
    void handlePrevious();
    void handleStop();

    void displayNowPlaying();
    void displayPlaylist(Playlist* playlist);

public:
    Application(PlaylistManager* manager, IAudioPlayer* audioPlayer,
                ILogger* logger, IUtility* utility);
    ~Application() = default;

    void run();
};

#endif
