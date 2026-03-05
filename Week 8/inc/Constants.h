#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

namespace Path {
    const std::string SONGS_DIR = "songs/";
    const std::string DATA_DIR  = "data/";
}

namespace Extensions {
    const std::string OGG = ".ogg";
    const std::string TXT = ".txt";
}

namespace Menu {
    const std::string MAIN =
        "\n=== Music Playlist ===\n"
        "1. Create Playlist\n"
        "2. Delete Playlist\n"
        "3. Select Playlist\n"
        "4. View All Playlists\n"
        "5. Exit\n"
        "Enter choice: ";

    const std::string PLAYLIST =
        "\n=== Playlist Menu ===\n"
        "1. Add Song\n"
        "2. Remove Song\n"
        "3. Move Song Up\n"
        "4. Move Song Down\n"
        "5. Play\n"
        "6. Back\n"
        "Enter choice: ";

    const std::string PLAYER =
        "\n=== Now Playing ===\n"
        "1. Pause / Resume\n"
        "2. Next Song\n"
        "3. Previous Song\n"
        "4. Stop\n"
        "5. Back to Playlist\n"
        "Enter choice: ";
}

namespace Prompt {
    const std::string ENTER_PLAYLIST_NAME = "Enter playlist name: ";
    const std::string SELECT_PLAYLIST = "Select playlist number: ";
    const std::string SELECT_SONG = "Select song number: ";
}

namespace Success {
    const std::string PLAYLIST_CREATED = "Playlist created successfully!\n";
    const std::string PLAYLIST_DELETED = "Playlist deleted successfully!\n";
    const std::string PLAYLIST_SAVED = "Playlist saved successfully!\n";
    const std::string SONG_ADDED = "Song added successfully!\n";
    const std::string SONG_REMOVED = "Song removed successfully!\n";
    const std::string SONG_MOVED_UP = "Song moved up successfully!\n";
    const std::string SONG_MOVED_DOWN = "Song moved down successfully!\n";
}

namespace Error {
    const std::string INVALID_CHOICE = "Invalid choice! Please try again.\n";
    const std::string INVALID_INPUT = "Invalid input! Please try again.\n";
    const std::string INVALID_INDEX = "Invalid index!\n";
    const std::string PLAYLIST_NOT_FOUND = "Playlist not found!\n";
    const std::string PLAYLIST_ALREADY_EXISTS = "Playlist already exists!\n";
    const std::string PLAYLIST_EMPTY = "Playlist is empty!\n";
    const std::string NO_PLAYLISTS = "No playlists found!\n";
    const std::string NO_SONGS_IN_LIBRARY = "No songs found in songs directory!\n";
    const std::string SONG_NOT_FOUND = "Song not found!\n";
    const std::string AUDIO_LOAD_FAILED = "Failed to load audio file!\n";
    const std::string CANNOT_MOVE_UP = "Cannot move song up - already at top!\n";
    const std::string CANNOT_MOVE_DOWN = "Cannot move song down - already at bottom!\n";
    const std::string FILE_OPEN_FAILED = "Failed to open file!\n";
    const std::string FILE_WRITE_FAILED = "Failed to write file!\n";
    const std::string INVALID_NAME = "Name cannot be empty!\n";
}

namespace Info {
    const std::string SEPARATOR = "========================================\n";
    const std::string WELCOME = "\nWelcome to Music Playlist!\n";
    const std::string GOODBYE = "Goodbye!\n";
    const std::string NOW_PLAYING = "Now Playing: ";
    const std::string PAUSED = "Paused: ";
    const std::string STOPPED = "Stopped.\n";
    const std::string SONG_PREFIX = "  Song ";
    const std::string CURRENT_MARKER = " [>>]";
    const std::string LIBRARY_HEADER = "\n=== Song Library ===\n";
    const std::string PLAYLIST_HEADER = "\n=== Playlist: ";
    const std::string PLAYLISTS_HEADER = "\n=== All Playlists ===\n";
    const std::string PLAYLIST_DISPLAY_START = " (";
    const std::string PLAYLISTS_DISPLAY_END = " songs)\n";
    const std::string NO_SONG_PLAYING = "No song currently selected.\n";
    const std::string NEWLINE = "\n";
    const std::string COLON_SPACE = ": ";
    const std::string HEADER_CLOSE = " ===\n";
}

#endif
