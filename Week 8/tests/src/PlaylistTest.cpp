#include <gtest/gtest.h>
#include "Playlist.h"
#include "Song.h"

class PlaylistTest : public ::testing::Test {
protected:
    Playlist* playlist;
    Song* songA;
    Song* songB;
    Song* songC;

    void SetUp() override {
        playlist = new Playlist("TestPlaylist");
        songA = new Song("Song A", "songs/a.ogg");
        songB = new Song("Song B", "songs/b.ogg");
        songC = new Song("Song C", "songs/c.ogg");
    }
    void TearDown() override {
        delete playlist;
        delete songA;
        delete songB;
        delete songC;
    }
};

TEST_F(PlaylistTest, NameIsCorrectOnCreation) {
    EXPECT_EQ(playlist->getName(), "TestPlaylist");
}

TEST_F(PlaylistTest, IsEmptyOnCreation) {
    EXPECT_EQ(playlist->getSongCount(), 0);
}

TEST_F(PlaylistTest, HasNoSongsOnCreation) {
    EXPECT_FALSE(playlist->hasSongs());
}

TEST_F(PlaylistTest, CurrentIndexIsZeroOnCreation) {
    EXPECT_EQ(playlist->getCurrentIndex(), 0);
}

TEST_F(PlaylistTest, GetCurrentSongReturnsNullWhenEmpty) {
    EXPECT_EQ(playlist->getCurrentSong(), nullptr);
}

TEST_F(PlaylistTest, AddSongIncreasesSongCount) {
    playlist->addSong(*songA);
    EXPECT_EQ(playlist->getSongCount(), 1);
}

TEST_F(PlaylistTest, AddMultipleSongsIncreasesSongCount) {
    playlist->addSong(*songA);
    playlist->addSong(*songB);
    playlist->addSong(*songC);
    EXPECT_EQ(playlist->getSongCount(), 3);
}

TEST_F(PlaylistTest, AddSongSetsHasSongsTrue) {
    playlist->addSong(*songA);
    EXPECT_TRUE(playlist->hasSongs());
}

TEST_F(PlaylistTest, AddSongPreservesOrder) {
    playlist->addSong(*songA);
    playlist->addSong(*songB);
    EXPECT_EQ(playlist->getSongs()[0].getTitle(), "Song A");
    EXPECT_EQ(playlist->getSongs()[1].getTitle(), "Song B");
}

TEST_F(PlaylistTest, RemoveSongReturnsTrueForValidIndex) {
    playlist->addSong(*songA);
    EXPECT_TRUE(playlist->removeSong(0));
}

TEST_F(PlaylistTest, RemoveSongDecreasesSongCount) {
    playlist->addSong(*songA);
    playlist->addSong(*songB);
    playlist->removeSong(0);
    EXPECT_EQ(playlist->getSongCount(), 1);
}

TEST_F(PlaylistTest, RemoveSongReturnsFalseForNegativeIndex) {
    playlist->addSong(*songA);
    EXPECT_FALSE(playlist->removeSong(-1));
}

TEST_F(PlaylistTest, RemoveSongReturnsFalseForOutOfBoundIndex) {
    playlist->addSong(*songA);
    EXPECT_FALSE(playlist->removeSong(5));
}

TEST_F(PlaylistTest, RemoveSongReturnsFalseOnEmptyPlaylist) {
    EXPECT_FALSE(playlist->removeSong(0));
}

TEST_F(PlaylistTest, RemoveSongRemovesCorrectSong) {
    playlist->addSong(*songA);
    playlist->addSong(*songB);
    playlist->removeSong(0);
    EXPECT_EQ(playlist->getSongs()[0].getTitle(), "Song B");
}

TEST_F(PlaylistTest, MoveSongUpReturnsTrueForValidIndex) {
    playlist->addSong(*songA);
    playlist->addSong(*songB);
    EXPECT_TRUE(playlist->moveSongUp(1));
}

TEST_F(PlaylistTest, MoveSongUpSwapsCorrectly) {
    playlist->addSong(*songA);
    playlist->addSong(*songB);
    playlist->moveSongUp(1);
    EXPECT_EQ(playlist->getSongs()[0].getTitle(), "Song B");
    EXPECT_EQ(playlist->getSongs()[1].getTitle(), "Song A");
}

TEST_F(PlaylistTest, MoveSongUpReturnsFalseForFirstSong) {
    playlist->addSong(*songA);
    playlist->addSong(*songB);
    EXPECT_FALSE(playlist->moveSongUp(0));
}

TEST_F(PlaylistTest, MoveSongUpReturnsFalseForNegativeIndex) {
    playlist->addSong(*songA);
    EXPECT_FALSE(playlist->moveSongUp(-1));
}

TEST_F(PlaylistTest, MoveSongUpReturnsFalseForOutOfBoundIndex) {
    playlist->addSong(*songA);
    EXPECT_FALSE(playlist->moveSongUp(5));
}

TEST_F(PlaylistTest, MoveSongDownReturnsTrueForValidIndex) {
    playlist->addSong(*songA);
    playlist->addSong(*songB);
    EXPECT_TRUE(playlist->moveSongDown(0));
}

TEST_F(PlaylistTest, MoveSongDownSwapsCorrectly) {
    playlist->addSong(*songA);
    playlist->addSong(*songB);
    playlist->moveSongDown(0);
    EXPECT_EQ(playlist->getSongs()[0].getTitle(), "Song B");
    EXPECT_EQ(playlist->getSongs()[1].getTitle(), "Song A");
}

TEST_F(PlaylistTest, MoveSongDownReturnsFalseForLastSong) {
    playlist->addSong(*songA);
    playlist->addSong(*songB);
    EXPECT_FALSE(playlist->moveSongDown(1));
}

TEST_F(PlaylistTest, MoveSongDownReturnsFalseForNegativeIndex) {
    playlist->addSong(*songA);
    EXPECT_FALSE(playlist->moveSongDown(-1));
}

TEST_F(PlaylistTest, MoveSongDownReturnsFalseOnSingleSong) {
    playlist->addSong(*songA);
    EXPECT_FALSE(playlist->moveSongDown(0));
}

TEST_F(PlaylistTest, NextReturnsFalseOnEmptyPlaylist) {
    EXPECT_FALSE(playlist->next());
}

TEST_F(PlaylistTest, NextReturnsTrueWhenNotAtEnd) {
    playlist->addSong(*songA);
    playlist->addSong(*songB);
    EXPECT_TRUE(playlist->next());
}

TEST_F(PlaylistTest, NextIncrementsCurrentIndex) {
    playlist->addSong(*songA);
    playlist->addSong(*songB);
    playlist->next();
    EXPECT_EQ(playlist->getCurrentIndex(), 1);
}

TEST_F(PlaylistTest, NextWrapsToFirstSongFromLast) {
    playlist->addSong(*songA);
    playlist->addSong(*songB);
    playlist->next(); 
    playlist->next();
    EXPECT_EQ(playlist->getCurrentIndex(), 0);
}

TEST_F(PlaylistTest, PreviousReturnsFalseOnEmptyPlaylist) {
    EXPECT_FALSE(playlist->previous());
}

TEST_F(PlaylistTest, PreviousReturnsTrueWhenNotAtStart) {
    playlist->addSong(*songA);
    playlist->addSong(*songB);
    playlist->next();
    EXPECT_TRUE(playlist->previous());
}

TEST_F(PlaylistTest, PreviousDecrementsCurrentIndex) {
    playlist->addSong(*songA);
    playlist->addSong(*songB);
    playlist->next();
    playlist->previous();
    EXPECT_EQ(playlist->getCurrentIndex(), 0);
}

TEST_F(PlaylistTest, PreviousWrapsToLastSongFromFirst) {
    playlist->addSong(*songA);
    playlist->addSong(*songB);
    playlist->addSong(*songC);
    playlist->previous();
    EXPECT_EQ(playlist->getCurrentIndex(), 2);
}

TEST_F(PlaylistTest, GetCurrentSongReturnsFirstSongAfterAdd) {
    playlist->addSong(*songA);
    EXPECT_EQ(playlist->getCurrentSong()->getTitle(), "Song A");
}

TEST_F(PlaylistTest, GetCurrentSongReturnsCorrectSongAfterNext) {
    playlist->addSong(*songA);
    playlist->addSong(*songB);
    playlist->next();
    EXPECT_EQ(playlist->getCurrentSong()->getTitle(), "Song B");
}

TEST_F(PlaylistTest, HasSongReturnsTrueForAddedSong) {
    playlist->addSong(*songA);
    EXPECT_TRUE(playlist->hasSong(*songA));
}

TEST_F(PlaylistTest, HasSongReturnsFalseForSongNotAdded) {
    playlist->addSong(*songA);
    EXPECT_FALSE(playlist->hasSong(*songB));
}

TEST_F(PlaylistTest, HasSongReturnsFalseOnEmptyPlaylist) {
    EXPECT_FALSE(playlist->hasSong(*songA));
}

TEST_F(PlaylistTest, ClearSongsEmptiesPlaylist) {
    playlist->addSong(*songA);
    playlist->addSong(*songB);
    playlist->clearSongs();
    EXPECT_EQ(playlist->getSongCount(), 0);
}

TEST_F(PlaylistTest, ClearSongsResetsCurrentIndex) {
    playlist->addSong(*songA);
    playlist->addSong(*songB);
    playlist->next();
    playlist->clearSongs();
    EXPECT_EQ(playlist->getCurrentIndex(), 0);
}

TEST_F(PlaylistTest, ClearSongsSetsHasSongsFalse) {
    playlist->addSong(*songA);
    playlist->clearSongs();
    EXPECT_FALSE(playlist->hasSongs());
}

TEST_F(PlaylistTest, CurrentIndexTracksMovedSongUp) {
    playlist->addSong(*songA);
    playlist->addSong(*songB);
    playlist->setCurrentIndex(1);
    playlist->moveSongUp(1);
    EXPECT_EQ(playlist->getCurrentIndex(), 0);
}

TEST_F(PlaylistTest, CurrentIndexTracksMovedSongDown) {
    playlist->addSong(*songA);
    playlist->addSong(*songB);
    playlist->setCurrentIndex(0);
    playlist->moveSongDown(0);
    EXPECT_EQ(playlist->getCurrentIndex(), 1);
}
