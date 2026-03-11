#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Application.h"
#include "PlaylistManager.h"
#include "MockAudioPlayer.h"
#include "MockLogger.h"
#include "MockUtility.h"
#include "Constants.h"
#include "Enums.h"

using ::testing::_;

class ApplicationTest : public ::testing::Test {
protected:
    ::testing::NiceMock<MockLogger>* mockLogger;
    ::testing::NiceMock<MockAudioPlayer>* mockAudio;
    ::testing::NiceMock<MockUtility>* mockUtility;
    PlaylistManager* manager;
    Application* app;

    void SetUp() override {
        mockLogger = new ::testing::NiceMock<MockLogger>();
        mockAudio = new ::testing::NiceMock<MockAudioPlayer>();
        mockUtility = new ::testing::NiceMock<MockUtility>();
        manager = new PlaylistManager(mockLogger);
        app = new Application(manager, mockAudio, mockLogger, mockUtility);
        EXPECT_CALL(*mockLogger, printMessage(_)).Times(::testing::AnyNumber());
        EXPECT_CALL(*mockLogger, printError(_)).Times(::testing::AnyNumber());
    }
    void TearDown() override {
        delete app;
        delete manager;
        delete mockAudio;
        delete mockUtility;
        delete mockLogger;
    }

    void expectExit() {
        EXPECT_CALL(*mockAudio, stop());
    }
};

TEST_F(ApplicationTest, ExitCallsAudioStop) {
    EXPECT_CALL(*mockAudio, stop()).Times(1);
    EXPECT_CALL(*mockUtility, getValidInteger())
        .WillOnce(::testing::Return(MAIN_EXIT));
    app->run();
}

TEST_F(ApplicationTest, ExitPrintsGoodbye) {
    EXPECT_CALL(*mockLogger, printMessage(Info::GOODBYE));
    EXPECT_CALL(*mockUtility, getValidInteger())
        .WillOnce(::testing::Return(MAIN_EXIT));
    EXPECT_CALL(*mockAudio, stop());
    app->run();
}

TEST_F(ApplicationTest, InvalidMainMenuChoicePrintsError) {
    EXPECT_CALL(*mockLogger, printError(Error::INVALID_CHOICE));
    EXPECT_CALL(*mockUtility, getValidInteger())
        .WillOnce(::testing::Return(99))
        .WillOnce(::testing::Return(MAIN_EXIT));
    EXPECT_CALL(*mockAudio, stop());
    app->run();
}

TEST_F(ApplicationTest, ViewAllPlaylistsPrintsErrorWhenEmpty) {
    EXPECT_CALL(*mockLogger, printError(Error::NO_PLAYLISTS));
    EXPECT_CALL(*mockUtility, getValidInteger())
        .WillOnce(::testing::Return(MAIN_VIEW_PLAYLISTS))
        .WillOnce(::testing::Return(MAIN_EXIT));
    EXPECT_CALL(*mockAudio, stop());
    app->run();
}

TEST_F(ApplicationTest, ViewAllPlaylistsPrintsHeaderWhenPlaylistsExist) {
    manager->createPlaylist("Chill");
    EXPECT_CALL(*mockLogger, printMessage(Info::PLAYLISTS_HEADER));
    EXPECT_CALL(*mockUtility, getValidInteger())
        .WillOnce(::testing::Return(MAIN_VIEW_PLAYLISTS))
        .WillOnce(::testing::Return(MAIN_EXIT));
    EXPECT_CALL(*mockAudio, stop());
    app->run();
}

TEST_F(ApplicationTest, CreatePlaylistPrintsSuccessForNewName) {
    system("mkdir -p data");
    EXPECT_CALL(*mockUtility, getValidFilename()).WillOnce(::testing::Return("MyList"));
    EXPECT_CALL(*mockLogger, printMessage(Success::PLAYLIST_CREATED));
    EXPECT_CALL(*mockUtility, getValidInteger())
        .WillOnce(::testing::Return(MAIN_CREATE_PLAYLIST))
        .WillOnce(::testing::Return(MAIN_EXIT));
    EXPECT_CALL(*mockAudio, stop());
    app->run();
    std::remove("data/MyList.txt");
}

TEST_F(ApplicationTest, CreatePlaylistPrintsErrorForDuplicateName) {
    system("mkdir -p data");
    manager->createPlaylist("MyList");
    EXPECT_CALL(*mockUtility, getValidFilename()).WillOnce(::testing::Return("MyList"));
    EXPECT_CALL(*mockLogger, printError(Error::PLAYLIST_ALREADY_EXISTS));
    EXPECT_CALL(*mockUtility, getValidInteger())
        .WillOnce(::testing::Return(MAIN_CREATE_PLAYLIST))
        .WillOnce(::testing::Return(MAIN_EXIT));
    EXPECT_CALL(*mockAudio, stop());
    app->run();
}

TEST_F(ApplicationTest, DeletePlaylistPrintsErrorWhenNoPlaylists) {
    EXPECT_CALL(*mockLogger, printError(Error::NO_PLAYLISTS));
    EXPECT_CALL(*mockUtility, getValidInteger())
        .WillOnce(::testing::Return(MAIN_DELETE_PLAYLIST))
        .WillOnce(::testing::Return(MAIN_EXIT));
    EXPECT_CALL(*mockAudio, stop());
    app->run();
}

TEST_F(ApplicationTest, DeletePlaylistRemovesItFromManager) {
    system("mkdir -p data");
    manager->createPlaylist("Workout");
    EXPECT_CALL(*mockUtility, getValidInteger())
        .WillOnce(::testing::Return(MAIN_DELETE_PLAYLIST))
        .WillOnce(::testing::Return(1))
        .WillOnce(::testing::Return(MAIN_EXIT));
    EXPECT_CALL(*mockAudio, stop());
    app->run();
    EXPECT_FALSE(manager->playlistExists("Workout"));
}

class ApplicationPlaylistTest : public ::testing::Test {
protected:
    ::testing::NiceMock<MockLogger>* mockLogger;
    ::testing::NiceMock<MockAudioPlayer>* mockAudio;
    ::testing::NiceMock<MockUtility>* mockUtility;
    PlaylistManager* manager;
    Application* app;

    void SetUp() override {
        system("mkdir -p data songs");
        mockLogger = new ::testing::NiceMock<MockLogger>();
        mockAudio = new ::testing::NiceMock<MockAudioPlayer>();
        mockUtility = new ::testing::NiceMock<MockUtility>();
        manager = new PlaylistManager(mockLogger);
        app = new Application(manager, mockAudio, mockLogger, mockUtility);

        manager->createPlaylist("TestList");
        manager->getPlaylist("TestList")->addSong(Song("Song A", "songs/a.ogg"));
        manager->getPlaylist("TestList")->addSong(Song("Song B", "songs/b.ogg"));
        EXPECT_CALL(*mockLogger, printMessage(_)).Times(::testing::AnyNumber());
        EXPECT_CALL(*mockLogger, printError(_)).Times(::testing::AnyNumber());
    }
    void TearDown() override {
        std::remove("data/TestList.txt");
        delete app;
        delete manager;
        delete mockAudio;
        delete mockUtility;
        delete mockLogger;
    }
};

TEST_F(ApplicationPlaylistTest, PlayCallsAudioPlayWithCorrectPath) {
    EXPECT_CALL(*mockAudio, play("songs/a.ogg")).WillOnce(::testing::Return(true));
    EXPECT_CALL(*mockAudio, stop()).Times(3);
    EXPECT_CALL(*mockUtility, getValidInteger())
        .WillOnce(::testing::Return(MAIN_SELECT_PLAYLIST))
        .WillOnce(::testing::Return(1))
        .WillOnce(::testing::Return(PLAYLIST_PLAY))
        .WillOnce(::testing::Return(PLAYER_STOP))
        .WillOnce(::testing::Return(PLAYLIST_BACK))
        .WillOnce(::testing::Return(MAIN_EXIT));
    app->run();
}

TEST_F(ApplicationPlaylistTest, PlayOnEmptyPlaylistPrintsError) {
    manager->getPlaylist("TestList")->removeSong(1);
    manager->getPlaylist("TestList")->removeSong(0);

    EXPECT_CALL(*mockLogger, printError(Error::PLAYLIST_EMPTY));
    EXPECT_CALL(*mockAudio, play(_)).Times(0);
    EXPECT_CALL(*mockAudio, stop()).Times(2);
    EXPECT_CALL(*mockUtility, getValidInteger())
        .WillOnce(::testing::Return(MAIN_SELECT_PLAYLIST))
        .WillOnce(::testing::Return(1))
        .WillOnce(::testing::Return(PLAYLIST_PLAY))
        .WillOnce(::testing::Return(PLAYLIST_BACK))
        .WillOnce(::testing::Return(MAIN_EXIT));
    app->run();
}

TEST_F(ApplicationPlaylistTest, PlayFailurePrintsAudioError) {
    EXPECT_CALL(*mockAudio, play(_)).WillOnce(::testing::Return(false));
    EXPECT_CALL(*mockLogger, printError(Error::AUDIO_LOAD_FAILED));
    EXPECT_CALL(*mockAudio, stop()).Times(2);
    EXPECT_CALL(*mockUtility, getValidInteger())
        .WillOnce(::testing::Return(MAIN_SELECT_PLAYLIST))
        .WillOnce(::testing::Return(1))
        .WillOnce(::testing::Return(PLAYLIST_PLAY))
        .WillOnce(::testing::Return(PLAYLIST_BACK))
        .WillOnce(::testing::Return(MAIN_EXIT));
    app->run();
}

TEST_F(ApplicationPlaylistTest, PauseResumeCallsPauseWhenPlaying) {
    EXPECT_CALL(*mockAudio, play(_)).WillOnce(::testing::Return(true));
    EXPECT_CALL(*mockAudio, isPlaying()).WillOnce(::testing::Return(true));
    EXPECT_CALL(*mockAudio, pause()).Times(1);
    EXPECT_CALL(*mockAudio, stop()).Times(3);
    EXPECT_CALL(*mockUtility, getValidInteger())
        .WillOnce(::testing::Return(MAIN_SELECT_PLAYLIST))
        .WillOnce(::testing::Return(1))
        .WillOnce(::testing::Return(PLAYLIST_PLAY))
        .WillOnce(::testing::Return(PLAYER_PAUSE_RESUME))
        .WillOnce(::testing::Return(PLAYER_STOP))
        .WillOnce(::testing::Return(PLAYLIST_BACK))
        .WillOnce(::testing::Return(MAIN_EXIT));
    app->run();
}

TEST_F(ApplicationPlaylistTest, PauseResumeCallsResumeWhenPaused) {
    EXPECT_CALL(*mockAudio, play(_)).WillOnce(::testing::Return(true));
    EXPECT_CALL(*mockAudio, isPlaying()).WillOnce(::testing::Return(false));
    EXPECT_CALL(*mockAudio, isPaused()).WillRepeatedly(::testing::Return(true));
    EXPECT_CALL(*mockAudio, resume()).Times(1);
    EXPECT_CALL(*mockAudio, stop()).Times(3);
    EXPECT_CALL(*mockUtility, getValidInteger())
        .WillOnce(::testing::Return(MAIN_SELECT_PLAYLIST))
        .WillOnce(::testing::Return(1))
        .WillOnce(::testing::Return(PLAYLIST_PLAY))
        .WillOnce(::testing::Return(PLAYER_PAUSE_RESUME))
        .WillOnce(::testing::Return(PLAYER_STOP))
        .WillOnce(::testing::Return(PLAYLIST_BACK))
        .WillOnce(::testing::Return(MAIN_EXIT));
    app->run();
}

TEST_F(ApplicationPlaylistTest, NextPlaysNextSong) {
    EXPECT_CALL(*mockAudio, play("songs/a.ogg")).WillOnce(::testing::Return(true));
    EXPECT_CALL(*mockAudio, play("songs/b.ogg")).WillOnce(::testing::Return(true));
    EXPECT_CALL(*mockAudio, stop()).Times(3);
    EXPECT_CALL(*mockUtility, getValidInteger())
        .WillOnce(::testing::Return(MAIN_SELECT_PLAYLIST))
        .WillOnce(::testing::Return(1))
        .WillOnce(::testing::Return(PLAYLIST_PLAY))
        .WillOnce(::testing::Return(PLAYER_NEXT))
        .WillOnce(::testing::Return(PLAYER_STOP))
        .WillOnce(::testing::Return(PLAYLIST_BACK))
        .WillOnce(::testing::Return(MAIN_EXIT));
    app->run();
}

TEST_F(ApplicationPlaylistTest, NextPrintsErrorOnAudioFailure) {
    EXPECT_CALL(*mockAudio, play("songs/a.ogg")).WillOnce(::testing::Return(true));
    EXPECT_CALL(*mockAudio, play("songs/b.ogg")).WillOnce(::testing::Return(false));
    EXPECT_CALL(*mockLogger, printError(Error::AUDIO_LOAD_FAILED));
    EXPECT_CALL(*mockAudio, stop()).Times(3);
    EXPECT_CALL(*mockUtility, getValidInteger())
        .WillOnce(::testing::Return(MAIN_SELECT_PLAYLIST))
        .WillOnce(::testing::Return(1))
        .WillOnce(::testing::Return(PLAYLIST_PLAY))
        .WillOnce(::testing::Return(PLAYER_NEXT))
        .WillOnce(::testing::Return(PLAYER_STOP))
        .WillOnce(::testing::Return(PLAYLIST_BACK))
        .WillOnce(::testing::Return(MAIN_EXIT));
    app->run();
}

TEST_F(ApplicationPlaylistTest, PreviousWrapsToLastSong) {
    EXPECT_CALL(*mockAudio, play("songs/a.ogg")).WillOnce(::testing::Return(true));
    EXPECT_CALL(*mockAudio, play("songs/b.ogg")).WillOnce(::testing::Return(true));
    EXPECT_CALL(*mockAudio, stop()).Times(3);
    EXPECT_CALL(*mockUtility, getValidInteger())
        .WillOnce(::testing::Return(MAIN_SELECT_PLAYLIST))
        .WillOnce(::testing::Return(1))
        .WillOnce(::testing::Return(PLAYLIST_PLAY))
        .WillOnce(::testing::Return(PLAYER_PREVIOUS))
        .WillOnce(::testing::Return(PLAYER_STOP))
        .WillOnce(::testing::Return(PLAYLIST_BACK))
        .WillOnce(::testing::Return(MAIN_EXIT));
    app->run();
}

TEST_F(ApplicationPlaylistTest, PreviousPrintsErrorOnAudioFailure) {
    EXPECT_CALL(*mockAudio, play("songs/a.ogg")).WillOnce(::testing::Return(true));
    EXPECT_CALL(*mockAudio, play("songs/b.ogg")).WillOnce(::testing::Return(false));
    EXPECT_CALL(*mockLogger, printError(Error::AUDIO_LOAD_FAILED));
    EXPECT_CALL(*mockAudio, stop()).Times(3);
    EXPECT_CALL(*mockUtility, getValidInteger())
        .WillOnce(::testing::Return(MAIN_SELECT_PLAYLIST))
        .WillOnce(::testing::Return(1))
        .WillOnce(::testing::Return(PLAYLIST_PLAY))
        .WillOnce(::testing::Return(PLAYER_PREVIOUS))
        .WillOnce(::testing::Return(PLAYER_STOP))
        .WillOnce(::testing::Return(PLAYLIST_BACK))
        .WillOnce(::testing::Return(MAIN_EXIT));
    app->run();
}

TEST_F(ApplicationPlaylistTest, StopCallsAudioStopAndPrintsMessage) {
    EXPECT_CALL(*mockAudio, play(_)).WillOnce(::testing::Return(true));
    EXPECT_CALL(*mockLogger, printMessage(Info::STOPPED));
    EXPECT_CALL(*mockAudio, stop()).Times(3);
    EXPECT_CALL(*mockUtility, getValidInteger())
        .WillOnce(::testing::Return(MAIN_SELECT_PLAYLIST))
        .WillOnce(::testing::Return(1))
        .WillOnce(::testing::Return(PLAYLIST_PLAY))
        .WillOnce(::testing::Return(PLAYER_STOP))
        .WillOnce(::testing::Return(PLAYLIST_BACK))
        .WillOnce(::testing::Return(MAIN_EXIT));
    app->run();
}
    