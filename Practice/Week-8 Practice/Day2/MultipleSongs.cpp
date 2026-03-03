#include <iostream>
#include <vector>
#include <SFML/Audio.hpp>

int main() {
    std::vector<std::string> playlist = {"Songs/AlienMusic.ogg", "Songs/Piano.ogg", "Songs/Guitar.ogg"};
    int currentIndex = 0;
    sf::Music music;
    if (!music.openFromFile(playlist[currentIndex])) {
        std::cout << "Error loading song.\n";
        return -1;
    }
    music.play();

    char choice;
    while (true) {
        std::cout << "\nN - Next | P - Previous | S - Pause | R - Resume | Q - Quit\n";
        std::cin >> choice;

        if (choice == 'N' || choice == 'n') {
            music.stop();
            currentIndex = (currentIndex + 1) % playlist.size();
            if (!music.openFromFile(playlist[currentIndex])) {
                std::cout << "Error loading song\n";
                continue;
            }
            music.play();
            std::cout << "Now Playing: " << playlist[currentIndex] << '\n';
        }
        else if (choice == 'P' || choice == 'p') {
            music.stop();
            currentIndex = (currentIndex - 1 + playlist.size()) % playlist.size();
            if (!music.openFromFile(playlist[currentIndex])) {
                std::cout << "Error loading song\n";
                continue;
            }
            music.play();
            std::cout << "Now Playing: " << playlist[currentIndex] << '\n';
        }
        else if (choice == 'S' || choice == 's') {
            music.pause();
        }
        else if (choice == 'R' || choice == 'r') {
            music.play();
        }
        else if (choice == 'Q' || choice == 'q') {
            break;
        }
    }
    return 0;
}
