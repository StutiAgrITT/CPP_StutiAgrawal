#ifndef IAUDIO_PLAYER_H
#define IAUDIO_PLAYER_H

#include <string>

class IAudioPlayer {
public:
    virtual ~IAudioPlayer() = default;
    virtual bool play(const std::string& filePath) = 0;
    virtual void pause() = 0;
    virtual void resume() = 0;
    virtual void stop() = 0;
    virtual bool isPlaying() const = 0;
    virtual bool isPaused() const = 0;
};

#endif
