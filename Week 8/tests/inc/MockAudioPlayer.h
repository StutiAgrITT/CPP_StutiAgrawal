#ifndef MOCK_AUDIO_PLAYER_H
#define MOCK_AUDIO_PLAYER_H

#include <gmock/gmock.h>
#include "IAudioPlayer.h"

class MockAudioPlayer : public IAudioPlayer {
public:
    MOCK_METHOD(bool, play, (const std::string& filePath), (override));
    MOCK_METHOD(void, pause, (), (override));
    MOCK_METHOD(void, resume, (), (override));
    MOCK_METHOD(void, stop, (), (override));
    MOCK_METHOD(bool, isPlaying, (), (const, override));
    MOCK_METHOD(bool, isPaused, (), (const, override));
};

#endif