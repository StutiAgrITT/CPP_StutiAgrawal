#include "Application.h"
#include "Constants.h"
#include "Exceptions.h"
#include <iostream>

Application::Application(PlaylistManager* manager, IAudioPlayer* audioPlayer,
                         ILogger* logger, IUtility* utility)
    : _manager(manager), _audioPlayer(audioPlayer),
      _logger(logger), _utility(utility),
      _isRunning(true), _currentPlaylist(nullptr) {}

void Application::run() {
    _manager->loadLibrary(Path::SONGS_DIR);
    _manager->loadAllPlaylists();
    _logger->printMessage(Info::WELCOME);

    while (_isRunning) {
        showMainMenu();
    }
}

void Application::showMainMenu() {
    _logger->printMessage(Menu::MAIN);
    int choice = _utility->getValidInteger();

    try {
        switch (choice) {
        case 1: 
            handleCreatePlaylist();
            break;
        case 2:
            handleDeletePlaylist();
            break;
        case 3:
            handleSelectPlaylist();
            break;
        case 4:
            handleViewAllPlaylists();
            break;
        case 5:
            _audioPlayer->stop();
            _logger->printMessage(Info::GOODBYE);
            _isRunning = false;
            break;
        default:
            _logger->printError(Error::INVALID_CHOICE);
        }
    }
    catch (std::exception& e) {
        _logger->printError(e.what());
    }
}

void Application::showPlaylistMenu() {
    if (!_currentPlaylist) return;

    bool inPlaylistMenu = true;
    while (inPlaylistMenu) {
        displayPlaylist(_currentPlaylist);
        _logger->printMessage(Menu::PLAYLIST);
        int choice = _utility->getValidInteger();

        try {
            switch (choice) {
            case 1:
                handleAddSong();
                break;
            case 2:
                handleRemoveSong();
                break;
            case 3:
                handleMoveSongUp();
                break;
            case 4:
                handleMoveSongDown();
                break;
            case 5:
                handlePlay();
                break;
            case 6:
                inPlaylistMenu = false;
                break;
            default:
                _logger->printError(Error::INVALID_CHOICE);
            }
        }
        catch (std::exception& e) {
            _logger->printError(e.what());
        }
    }
}

void Application::showPlayerMenu() {
    bool inPlayerMenu = true;
    while (inPlayerMenu) {
        displayNowPlaying();
        _logger->printMessage(Menu::PLAYER);
        int choice = _utility->getValidInteger();

        try {
            switch (choice) {
            case 1:
                handlePauseResume();
                break;
            case 2:
                handleNext();
                break;
            case 3:
                handlePrevious();
                break;
            case 4:
                handleStop();
                inPlayerMenu = false;
                break;
            case 5:
                inPlayerMenu = false;
                break;
            default: _logger->printError(Error::INVALID_CHOICE);
            }
        }
        catch (std::exception& e) {
            _logger->printError(e.what());
        }
    }
}

void Application::handleCreatePlaylist() {
    _logger->printMessage(Prompt::ENTER_PLAYLIST_NAME);
    std::string name = _utility->getValidFilename();

    if (_manager->createPlaylist(name)) {
        _manager->savePlaylist(name);
        _logger->printMessage(Success::PLAYLIST_CREATED);
    }
    else {
        _logger->printError(Error::PLAYLIST_ALREADY_EXISTS);
    }
}

void Application::handleDeletePlaylist() {
    const auto& playlists = _manager->getPlaylists();
    if (playlists.empty()) {
        _logger->printError(Error::NO_PLAYLISTS);
        return;
    }

    handleViewAllPlaylists();
    _logger->printMessage(Prompt::SELECT_PLAYLIST);
    int choice = _utility->getValidInteger();

    int index = 1;
    for (const auto& pair : playlists) {
        if (index == choice) {
            if (_currentPlaylist && _currentPlaylist->getName() == pair.first) {
                _audioPlayer->stop();
                _currentPlaylist = nullptr;
            }
            _manager->deletePlaylist(pair.first);
            _logger->printMessage(Success::PLAYLIST_DELETED);
            return;
        }
        index++;
    }
    _logger->printError(Error::INVALID_INDEX);
}

void Application::handleSelectPlaylist() {
    const auto& playlists = _manager->getPlaylists();
    if (playlists.empty()) {
        _logger->printError(Error::NO_PLAYLISTS);
        return;
    }

    handleViewAllPlaylists();
    _logger->printMessage(Prompt::SELECT_PLAYLIST);
    int choice = _utility->getValidInteger();

    int index = 1;
    for (auto& pair : _manager->getPlaylists()) {
        if (index == choice) {
            _currentPlaylist = _manager->getPlaylist(pair.first);
            showPlaylistMenu();
            return;
        }
        index++;
    }
    _logger->printError(Error::INVALID_INDEX);
}

void Application::handleViewAllPlaylists() {
    const auto& playlists = _manager->getPlaylists();
    if (playlists.empty()) {
        _logger->printError(Error::NO_PLAYLISTS);
        return;
    }

    _logger->printMessage(Info::PLAYLISTS_HEADER);
    int index = 1;
    for (const auto& pair : playlists) {
        _logger->printMessage(std::to_string(index) + Info::COLON_SPACE +
                              pair.first + " (" +
                              std::to_string(pair.second.getSongCount()) +
                              " songs)\n");
        index++;
    }
}

void Application::handleAddSong() {
    const std::vector<Song>& library = _manager->getSongLibrary();
    if (library.empty()) {
        _logger->printError(Error::NO_SONGS_IN_LIBRARY);
        return;
    }

    displayLibrary();
    _logger->printMessage(Prompt::SELECT_SONG);
    int choice = _utility->getValidInteger();

    if (choice < 1 || choice > static_cast<int>(library.size())) {
        _logger->printError(Error::INVALID_INDEX);
        return;
    }

    _currentPlaylist->addSong(library[choice - 1]);
    _manager->savePlaylist(_currentPlaylist->getName());
    _logger->printMessage(Success::SONG_ADDED);
}

void Application::handleRemoveSong() {
    if (!_currentPlaylist->hasSongs()) {
        _logger->printError(Error::PLAYLIST_EMPTY);
        return;
    }

    displayPlaylist(_currentPlaylist);
    _logger->printMessage(Prompt::SELECT_SONG);
    int choice = _utility->getValidInteger();

    if (_currentPlaylist->removeSong(choice - 1)) {
        _manager->savePlaylist(_currentPlaylist->getName());
        _logger->printMessage(Success::SONG_REMOVED);
    } else {
        _logger->printError(Error::INVALID_INDEX);
    }
}

void Application::handleMoveSongUp() {
    if (!_currentPlaylist->hasSongs()) {
        _logger->printError(Error::PLAYLIST_EMPTY);
        return;
    }

    displayPlaylist(_currentPlaylist);
    _logger->printMessage(Prompt::SELECT_SONG);
    int choice = _utility->getValidInteger();

    if (_currentPlaylist->moveSongUp(choice - 1)) {
        _manager->savePlaylist(_currentPlaylist->getName());
        _logger->printMessage(Success::SONG_MOVED_UP);
    } else {
        _logger->printError(Error::CANNOT_MOVE_UP);
    }
}

void Application::handleMoveSongDown() {
    if (!_currentPlaylist->hasSongs()) {
        _logger->printError(Error::PLAYLIST_EMPTY);
        return;
    }

    displayPlaylist(_currentPlaylist);
    _logger->printMessage(Prompt::SELECT_SONG);
    int choice = _utility->getValidInteger();

    if (_currentPlaylist->moveSongDown(choice - 1)) {
        _manager->savePlaylist(_currentPlaylist->getName());
        _logger->printMessage(Success::SONG_MOVED_DOWN);
    } else {
        _logger->printError(Error::CANNOT_MOVE_DOWN);
    }
}

void Application::handlePlay() {
    if (!_currentPlaylist->hasSongs()) {
        _logger->printError(Error::PLAYLIST_EMPTY);
        return;
    }

    Song* song = _currentPlaylist->getCurrentSong();
    if (!song) return;

    if (!_audioPlayer->play(song->getFilePath())) {
        _logger->printError(Error::AUDIO_LOAD_FAILED);
        return;
    }

    showPlayerMenu();
}

void Application::handlePauseResume() {
    if (_audioPlayer->isPlaying()) {
        _audioPlayer->pause();
    } else if (_audioPlayer->isPaused()) {
        _audioPlayer->resume();
    }
}

void Application::handleNext() {
    if (!_currentPlaylist->next()) return;

    Song* song = _currentPlaylist->getCurrentSong();
    if (!song) return;

    _audioPlayer->play(song->getFilePath());
}

void Application::handlePrevious() {
    if (!_currentPlaylist->previous()) return;

    Song* song = _currentPlaylist->getCurrentSong();
    if (!song) return;

    _audioPlayer->play(song->getFilePath());
}

void Application::handleStop() {
    _audioPlayer->stop();
    _logger->printMessage(Info::STOPPED);
}

void Application::displayNowPlaying() {
    Song* song = _currentPlaylist ? _currentPlaylist->getCurrentSong() : nullptr;
    if (!song) {
        _logger->printMessage(Info::NO_SONG_PLAYING);
        return;
    }

    std::string status = _audioPlayer->isPaused() ? Info::PAUSED : Info::NOW_PLAYING;
    _logger->printMessage(Info::SEPARATOR);
    _logger->printMessage(status + song->getTitle() + Info::NEWLINE);
    _logger->printMessage(Info::SEPARATOR);
}

void Application::displayPlaylist(Playlist* playlist) {
    _logger->printMessage(Info::PLAYLIST_HEADER + playlist->getName() + Info::HEADER_CLOSE);

    if (!playlist->hasSongs()) {
        _logger->printMessage(Info::NO_SONG_PLAYING);
        return;
    }

    const auto& songs = playlist->getSongs();
    for (int i = 0; i < static_cast<int>(songs.size()); i++) {
        std::string line = std::to_string(i + 1) + Info::COLON_SPACE +
                           songs[i].getTitle();

        if (i == playlist->getCurrentIndex()) {
            line += Info::CURRENT_MARKER;
        }
        _logger->printMessage(line + Info::NEWLINE);
    }
}

void Application::displayLibrary() {
    const auto& library = _manager->getSongLibrary();
    _logger->printMessage(Info::LIBRARY_HEADER);

    for (int i = 0; i < static_cast<int>(library.size()); i++) {
        _logger->printMessage(std::to_string(i + 1) + Info::COLON_SPACE +
                              library[i].getTitle() + Info::NEWLINE);
    }
}
