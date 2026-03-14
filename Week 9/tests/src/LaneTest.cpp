#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Lane.h"
#include "MockTrafficLight.h"
#include <thread>

class LaneTest : public ::testing::Test {
protected:
    MockTrafficLight* mockLight;
    Lane* lane;

    void SetUp() override {
        mockLight = new MockTrafficLight();
        lane = new Lane(LANE_1);
        lane->setLight(mockLight);
    }

    void TearDown() override {
        delete lane;
        delete mockLight;
    }
};

TEST_F(LaneTest, GetLaneIdReturnsCorrectId) {
    EXPECT_CALL(*mockLight, getState(LANE_1)).Times(::testing::AnyNumber());
    EXPECT_EQ(lane->getLaneId(), LANE_1);
}

TEST_F(LaneTest, EnterProceedsWhenLightIsGreen) {
    EXPECT_CALL(*mockLight, getState(LANE_1))
        .WillRepeatedly(::testing::Return(GREEN));

    bool entered = false;
    std::thread t([&]() {
        lane->enter();
        entered = true;
    });

    t.join();
    EXPECT_TRUE(entered);
    lane->release();
}

TEST_F(LaneTest, EnterBlocksWhenLightIsRed) {
    EXPECT_CALL(*mockLight, getState(LANE_1))
        .WillRepeatedly(::testing::Return(RED));

    bool entered = false;
    std::thread t([&]() {
        lane->enter();
        entered = true;
    });

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    EXPECT_FALSE(entered);

    lane->stop();
    t.join();
}

TEST_F(LaneTest, EnterBlocksWhenLightIsYellow) {
    EXPECT_CALL(*mockLight, getState(LANE_1))
        .WillRepeatedly(::testing::Return(YELLOW));

    bool entered = false;
    std::thread t([&]() {
        lane->enter();
        entered = true;
    });

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    EXPECT_FALSE(entered);

    lane->stop();
    t.join();
}

TEST_F(LaneTest, StopWakesUpWaitingThread) {
    EXPECT_CALL(*mockLight, getState(LANE_1))
        .WillRepeatedly(::testing::Return(RED));

    bool exited = false;
    std::thread t([lane = lane, &exited]() {
        lane->enter();
        exited = true;
    });

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    lane->stop();
    t.join();
    EXPECT_TRUE(exited);
}

TEST_F(LaneTest, NotifyWakesUpWaitingThreadWhenGreen) {
    EXPECT_CALL(*mockLight, getState(LANE_1))
        .WillOnce(::testing::Return(RED))
        .WillRepeatedly(::testing::Return(GREEN));

    bool entered = false;
    std::thread t([&]() {
        lane->enter();
        entered = true;
    });

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    lane->notify();
    t.join();
    EXPECT_TRUE(entered);
    lane->release();
}
