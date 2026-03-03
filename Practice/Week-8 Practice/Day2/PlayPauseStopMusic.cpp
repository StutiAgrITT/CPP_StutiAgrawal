#include <SFML/Audio.hpp>
#include <iostream>

int main() {
    sf::Music music;

    if (!music.openFromFile("Songs/AlienMusic.ogg")) {
        std::cout << "Error loading file\n";
        return -1;
    }

    char choice;

    while (true) {
        std::cout << "\nP - Play\nA - Pause\nS - Stop\nQ - Quit\n";
        std::cin >> choice;

        if (choice == 'P' || choice == 'p')
            music.play();
        else if (choice == 'A' || choice == 'a')
            music.pause();
        else if (choice == 'S' || choice == 's')
            music.stop();
        else if (choice == 'Q' || choice == 'q')
            break;
    }
    return 0;
}