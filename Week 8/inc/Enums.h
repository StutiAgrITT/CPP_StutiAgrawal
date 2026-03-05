#ifndef ENUMS_H
#define ENUMS_H

enum MainMenuChoice {
    MAIN_CREATE_PLAYLIST = 1,
    MAIN_DELETE_PLAYLIST = 2,
    MAIN_SELECT_PLAYLIST = 3,
    MAIN_VIEW_PLAYLISTS = 4,
    MAIN_EXIT = 5
};

enum PlaylistMenuChoice {
    PLAYLIST_ADD_SONG = 1,
    PLAYLIST_REMOVE_SONG = 2,
    PLAYLIST_MOVE_UP = 3,
    PLAYLIST_MOVE_DOWN = 4,
    PLAYLIST_PLAY = 5,
    PLAYLIST_BACK = 6
};

enum PlayerMenuChoice {
    PLAYER_PAUSE_RESUME = 1,
    PLAYER_NEXT = 2,
    PLAYER_PREVIOUS = 3,
    PLAYER_STOP = 4,
    PLAYER_BACK = 5
};

#endif
