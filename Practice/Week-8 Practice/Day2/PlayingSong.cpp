#include <iostream>
#include <SFML/Audio.hpp>

int main() {
    sf::Music music;

    if(!music.openFromFile("Songs/AlienMusic.ogg")) {
        std::cout << "Error loading file.\n";
        return -1;
    }

    music.play();
    std::cout << "Playing. Press enter to stop.\n";
    std::cin.get();
    return 0;
}