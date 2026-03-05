#ifndef AUDIO_PLAYER_H
#define AUDIO_PLAYER_H

#include "IAudioPlayer.h"
#include <SFML/Audio.hpp>

class AudioPlayer : public IAudioPlayer {
private:
    sf::Music _music;

public:
    AudioPlayer() = default;
    ~AudioPlayer() override = default;

    bool play(const std::string& filePath) override;
    void pause() override;
    void resume() override;
    void stop() override;
    bool isPlaying() const override;
    bool isPaused() const override;
};

#endif
