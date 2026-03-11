#include "Application.h"
#include "Constants.h"
#include "Exceptions.h"
#include "Enums.h"
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
        case MAIN_CREATE_PLAYLIST:
            handleCreatePlaylist();
            break;
        case MAIN_DELETE_PLAYLIST:
            handleDeletePlaylist();
            break;
        case MAIN_SELECT_PLAYLIST:
            handleSelectPlaylist();
            break;
        case MAIN_VIEW_PLAYLISTS:
            handleViewAllPlaylists();
            break;
        case MAIN_EXIT:
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
        _manager->refreshSongsFromLibrary(_currentPlaylist->getName());
        displayPlaylist(_currentPlaylist);
        _logger->printMessage(Menu::PLAYLIST);
        int choice = _utility->getValidInteger();

        try {
            switch (choice) {
            case PLAYLIST_ADD_SONG                                                          :
                handleAddSong();
                break;
            case PLAYLIST_REMOVE_SONG:
                handleRemoveSong();
                break;
            case PLAYLIST_MOVE_UP:
                handleMoveSongUp();
                break;
            case PLAYLIST_MOVE_DOWN:
                handleMoveSongDown();
                break;
            case PLAYLIST_PLAY:
                handlePlay(); 
                break;
            case PLAYLIST_BACK:
                _audioPlayer->stop();
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
            case PLAYER_PAUSE_RESUME:
                handlePauseResume();
                break;
            case PLAYER_NEXT:
                handleNext();
                break;
            case PLAYER_PREVIOUS:
                handlePrevious();
                break;
            case PLAYER_STOP:
                handleStop();
                inPlayerMenu = false;
                break;
            case PLAYER_BACK:
                inPlayerMenu = false;
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
            pair.first + Info::PLAYLIST_DISPLAY_START +
            std::to_string(pair.second.getSongCount()) +
            Info::PLAYLISTS_DISPLAY_END);
        index++;
    }
}

void Application::handleAddSong() {
    const std::vector<Song>& library = _manager->getSongLibrary();
    if (library.empty()) {
        _logger->printError(Error::NO_SONGS_IN_LIBRARY);
        return;
    }

    bool adding = true;
    while (adding) {
        std::vector<const Song*> available;
        for (const Song& song : library) {
            if (!_currentPlaylist->hasSong(song)) {
                available.push_back(&song);
            }
        }
        if (available.empty()) {
            _logger->printMessage(Error::ALL_SONGS_ADDED);
            return;
        }
        _logger->printMessage(Info::LIBRARY_HEADER);
        for (int index = 0; index < (available.size()); index++) {
            _logger->printMessage(std::to_string(index + 1) + Info::COLON_SPACE +
                                  available[index]->getTitle() + Info::NEWLINE);
        }
        _logger->printMessage(Prompt::SELECT_SONG_OR_DONE);
        int choice = _utility->getValidInteger();

        if (choice == 0) {
            adding = false;
            return;
        }
        if (choice < 1 || choice > (available.size())) {
            _logger->printError(Error::INVALID_INDEX);
            continue;
        }
        _currentPlaylist->addSong(*available[choice - 1]);
        _manager->savePlaylist(_currentPlaylist->getName());
        _logger->printMessage(Success::SONG_ADDED);
    }
}

void Application::handleRemoveSong() {
    if (!_currentPlaylist->hasSongs()) {
        _logger->printError(Error::PLAYLIST_EMPTY);
        return;
    }

    displayPlaylist(_currentPlaylist);
    _logger->printMessage(Prompt::SELECT_SONG);
    int choice = _utility->getValidInteger();

    if (choice < 1 || choice > _currentPlaylist->getSongCount()) {
        _logger->printError(Error::INVALID_INDEX);
        return;
    }

    _currentPlaylist->removeSong(choice - 1);
    _manager->savePlaylist(_currentPlaylist->getName());
    _logger->printMessage(Success::SONG_REMOVED);
}

void Application::handleMoveSongUp() {
    if (!_currentPlaylist->hasSongs()) {
        _logger->printError(Error::PLAYLIST_EMPTY);
        return;
    }

    displayPlaylist(_currentPlaylist);
    _logger->printMessage(Prompt::SELECT_SONG);
    int choice = _utility->getValidInteger();

    if (choice < 1 || choice > _currentPlaylist->getSongCount()) {
        _logger->printError(Error::INVALID_INDEX);
        return;
    }

    if (!_currentPlaylist->moveSongUp(choice - 1)) {
        _logger->printError(Error::CANNOT_MOVE_UP);
    }
    else {
        _manager->savePlaylist(_currentPlaylist->getName());
        _logger->printMessage(Success::SONG_MOVED_UP);
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

    if (choice < 1 || choice > _currentPlaylist->getSongCount()) {
        _logger->printError(Error::INVALID_INDEX);
        return;
    }

    if (!_currentPlaylist->moveSongDown(choice - 1)) {
        _logger->printError(Error::CANNOT_MOVE_DOWN);
    }
    else {
        _manager->savePlaylist(_currentPlaylist->getName());
        _logger->printMessage(Success::SONG_MOVED_DOWN);
    }
}

void Application::handlePlay() {
    if (!_currentPlaylist->hasSongs()) {
        _logger->printError(Error::PLAYLIST_EMPTY);
        return;
    }

    _currentPlaylist->setCurrentIndex(0);
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
    }
    else if (_audioPlayer->isPaused()) {
        _audioPlayer->resume();
    }
}

void Application::handleNext() {
    if (!_currentPlaylist->next()) return;

    Song* song = _currentPlaylist->getCurrentSong();
    if (!song) return;

    if(!_audioPlayer->play(song->getFilePath())) {
        _logger->printError(Error::AUDIO_LOAD_FAILED);
    }
}

void Application::handlePrevious() {
    if (!_currentPlaylist->previous()) return;

    Song* song = _currentPlaylist->getCurrentSong();
    if (!song) return;

    if(!_audioPlayer->play(song->getFilePath())) {
        _logger->printError(Error::AUDIO_LOAD_FAILED);
    }
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
    for (int index = 0; index < (songs.size()); index++) {
        std::string line = std::to_string(index + 1) + Info::COLON_SPACE +
                           songs[index].getTitle();

        if (index == playlist->getCurrentIndex()) {
            line += Info::CURRENT_MARKER;
        }
        _logger->printMessage(line + Info::NEWLINE);
    }
}
