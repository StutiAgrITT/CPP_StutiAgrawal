#include <gtest/gtest.h>
#include "Song.h"

class SongTest : public ::testing::Test {
protected:
    Song* song;
    void SetUp() override {
        song = new Song("Chances", "songs/chances.ogg");
    }
    void TearDown() override {
        delete song;
    }
};

TEST_F(SongTest, GetTitleReturnsCorrectValue) {
    EXPECT_EQ(song->getTitle(), "Chances");
}

TEST_F(SongTest, GetFilePathReturnsCorrectValue) {
    EXPECT_EQ(song->getFilePath(), "songs/chances.ogg");
}

TEST_F(SongTest, EqualityReturnsTrueForSameFilePath) {
    Song other("Different Title", "songs/chances.ogg");
    EXPECT_TRUE(*song == other);
}

TEST_F(SongTest, EqualityReturnsFalseForDifferentFilePath) {
    Song other("Chances", "songs/everybody.ogg");
    EXPECT_FALSE(*song == other);
}

TEST_F(SongTest, SongWithEmptyTitleIsValid) {
    Song empty("", "songs/test.ogg");
    EXPECT_EQ(empty.getTitle(), "");
}
