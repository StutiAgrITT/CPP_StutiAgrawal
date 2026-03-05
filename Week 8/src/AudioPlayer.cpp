#include "AudioPlayer.h"
#include "Exceptions.h"
#include "Constants.h"

bool AudioPlayer::play(const std::string& filePath) {
    _music.stop();
    if (!_music.openFromFile(filePath)) {
        return false;
    }
    _music.play();
    return true;
}

void AudioPlayer::pause() {
    if (_music.getStatus() == sf::Music::Playing) {
        _music.pause();
    }
}

void AudioPlayer::resume() {
    if (_music.getStatus() == sf::Music::Paused) {
        _music.play();
    }
}

void AudioPlayer::stop() {
    _music.stop();
}

bool AudioPlayer::isPlaying() const {
    return _music.getStatus() == sf::Music::Playing;
}

bool AudioPlayer::isPaused() const {
    return _music.getStatus() == sf::Music::Paused;
}
