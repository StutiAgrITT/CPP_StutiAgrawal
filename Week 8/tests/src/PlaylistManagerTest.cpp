#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "PlaylistManager.h"
#include "MockLogger.h"
#include "Constants.h"
#include <fstream>

class PlaylistManagerTest : public ::testing::Test {
protected:
    ::testing::NiceMock<MockLogger>* mockLogger;
    PlaylistManager* manager;

    void SetUp() override {
        mockLogger = new ::testing::NiceMock<MockLogger>();
        manager = new PlaylistManager(mockLogger);
    }
    void TearDown() override {
        delete manager;
        delete mockLogger;
    }
};

TEST_F(PlaylistManagerTest, InitiallyNoPlaylists) {
    EXPECT_TRUE(manager->getPlaylists().empty());
}

TEST_F(PlaylistManagerTest, InitiallyEmptySongLibrary) {
    EXPECT_TRUE(manager->getSongLibrary().empty());
}

TEST_F(PlaylistManagerTest, CreatePlaylistReturnsTrueForNewName) {
    EXPECT_TRUE(manager->createPlaylist("Workout"));
}

TEST_F(PlaylistManagerTest, CreatePlaylistAddsToMap) {
    manager->createPlaylist("Workout");
    EXPECT_EQ(manager->getPlaylists().size(), 1);
}

TEST_F(PlaylistManagerTest, CreatePlaylistReturnsFalseForDuplicateName) {
    manager->createPlaylist("Workout");
    EXPECT_FALSE(manager->createPlaylist("Workout"));
}

TEST_F(PlaylistManagerTest, CreatePlaylistDoesNotAddDuplicate) {
    manager->createPlaylist("Workout");
    manager->createPlaylist("Workout");
    EXPECT_EQ(manager->getPlaylists().size(), 1);
}

TEST_F(PlaylistManagerTest, CreateMultiplePlaylistsAddsAll) {
    manager->createPlaylist("Workout");
    manager->createPlaylist("Chill");
    manager->createPlaylist("Party");
    EXPECT_EQ(manager->getPlaylists().size(), 3);
}

TEST_F(PlaylistManagerTest, DeletePlaylistReturnsTrueForExistingPlaylist) {
    manager->createPlaylist("Workout");
    EXPECT_TRUE(manager->deletePlaylist("Workout"));
}

TEST_F(PlaylistManagerTest, DeletePlaylistRemovesFromMap) {
    manager->createPlaylist("Workout");
    manager->deletePlaylist("Workout");
    EXPECT_TRUE(manager->getPlaylists().empty());
}

TEST_F(PlaylistManagerTest, DeletePlaylistReturnsFalseForNonExistentPlaylist) {
    EXPECT_FALSE(manager->deletePlaylist("NonExistent"));
}

TEST_F(PlaylistManagerTest, DeletePlaylistDoesNotAffectOthers) {
    manager->createPlaylist("Workout");
    manager->createPlaylist("Chill");
    manager->deletePlaylist("Workout");
    EXPECT_EQ(manager->getPlaylists().size(), 1);
    EXPECT_TRUE(manager->playlistExists("Chill"));
}

TEST_F(PlaylistManagerTest, GetPlaylistReturnsNonNullForExisting) {
    manager->createPlaylist("Workout");
    EXPECT_NE(manager->getPlaylist("Workout"), nullptr);
}

TEST_F(PlaylistManagerTest, GetPlaylistReturnsNullForNonExistent) {
    EXPECT_EQ(manager->getPlaylist("NonExistent"), nullptr);
}

TEST_F(PlaylistManagerTest, GetPlaylistReturnsCorrectName) {
    manager->createPlaylist("Workout");
    EXPECT_EQ(manager->getPlaylist("Workout")->getName(), "Workout");
}

TEST_F(PlaylistManagerTest, PlaylistExistsReturnsTrueAfterCreate) {
    manager->createPlaylist("Workout");
    EXPECT_TRUE(manager->playlistExists("Workout"));
}

TEST_F(PlaylistManagerTest, PlaylistExistsReturnsFalseForNonExistent) {
    EXPECT_FALSE(manager->playlistExists("NonExistent"));
}

TEST_F(PlaylistManagerTest, PlaylistExistsReturnsFalseAfterDelete) {
    manager->createPlaylist("Workout");
    manager->deletePlaylist("Workout");
    EXPECT_FALSE(manager->playlistExists("Workout"));
}

TEST_F(PlaylistManagerTest, PlaylistsAreStoredAlphabetically) {
    manager->createPlaylist("Workout");
    manager->createPlaylist("Chill");
    manager->createPlaylist("Party");

    auto it = manager->getPlaylists().begin();
    EXPECT_EQ(it->first, "Chill");
    ++it;
    EXPECT_EQ(it->first, "Party");
    ++it;
    EXPECT_EQ(it->first, "Workout");
}

class PlaylistManagerSaveTest : public ::testing::Test {
protected:
    ::testing::StrictMock<MockLogger>* mockLogger;
    PlaylistManager* manager;

    void SetUp() override {
        system("mkdir -p data");
        mockLogger = new ::testing::StrictMock<MockLogger>();
        manager = new PlaylistManager(mockLogger);
        manager->createPlaylist("TestList");
    }
    void TearDown() override {
        std::remove("data/TestList.txt");
        delete manager;
        delete mockLogger;
    }
};

TEST_F(PlaylistManagerSaveTest, SavePlaylistDoesNotLogAnything) {
    manager->savePlaylist("TestList");
}

TEST_F(PlaylistManagerSaveTest, SavePlaylistCreatesFile) {
    manager->savePlaylist("TestList");
    std::ifstream file("data/TestList.txt");
    EXPECT_TRUE(file.good());
}

TEST_F(PlaylistManagerSaveTest, SavePlaylistWritesSongFilenames) {
    ::testing::NiceMock<MockLogger> niceMock;
    PlaylistManager tempManager(&niceMock);
    system("mkdir -p /tmp/pm_test_songs");
    std::ofstream ogg("/tmp/pm_test_songs/MySong.ogg");
    ogg.close();
    tempManager.loadLibrary("/tmp/pm_test_songs/");
    tempManager.createPlaylist("TempList");
    tempManager.getPlaylist("TempList")->addSong(tempManager.getSongLibrary()[0]);
    tempManager.savePlaylist("TempList");

    std::ifstream f("data/TempList.txt");
    std::string line;
    std::getline(f, line);
    EXPECT_EQ(line, "MySong.ogg");

    std::remove("data/TempList.txt");
    system("rm -rf /tmp/pm_test_songs");
}

class PlaylistManagerLibraryTest : public ::testing::Test {
protected:
    ::testing::NiceMock<MockLogger>* mockLogger;
    PlaylistManager* manager;
    const std::string testSongsDir = "/tmp/playlist_lib_test/";

    void SetUp() override {
        mockLogger = new ::testing::NiceMock<MockLogger>();
        manager = new PlaylistManager(mockLogger);
        system(("mkdir -p " + testSongsDir).c_str());

        std::ofstream(testSongsDir + "Alpha.ogg").close();
        std::ofstream(testSongsDir + "Beta.ogg").close();
        std::ofstream(testSongsDir + "readme.txt").close();

        manager->loadLibrary(testSongsDir);
    }
    void TearDown() override {
        system(("rm -rf " + testSongsDir).c_str());
        delete manager;
        delete mockLogger;
    }
};

TEST_F(PlaylistManagerLibraryTest, LoadLibraryFindsOggFiles) {
    EXPECT_EQ(manager->getSongLibrary().size(), 2);
}

TEST_F(PlaylistManagerLibraryTest, LoadLibraryIgnoresNonOggFiles) {
    EXPECT_EQ(manager->getSongLibrary().size(), 2);
}

TEST_F(PlaylistManagerLibraryTest, LoadLibrarySongsAreSortedAlphabetically) {
    EXPECT_EQ(manager->getSongLibrary()[0].getTitle(), "Alpha");
    EXPECT_EQ(manager->getSongLibrary()[1].getTitle(), "Beta");
}

TEST_F(PlaylistManagerLibraryTest, LoadLibraryStripsOggExtensionFromTitle) {
    EXPECT_EQ(manager->getSongLibrary()[0].getTitle(), "Alpha");
}

TEST_F(PlaylistManagerLibraryTest, LoadLibrarySongHasCorrectFilePath) {
    EXPECT_EQ(manager->getSongLibrary()[0].getFilePath(), testSongsDir + "Alpha.ogg");
}

TEST_F(PlaylistManagerLibraryTest, LoadLibraryReplacesOldLibraryOnReload) {
    std::ofstream(testSongsDir + "Gamma.ogg").close();
    manager->loadLibrary(testSongsDir);
    EXPECT_EQ(manager->getSongLibrary().size(), 3);
}
