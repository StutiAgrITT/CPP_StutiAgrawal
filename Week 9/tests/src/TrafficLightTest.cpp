#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "TrafficLight.h"
#include "MockLane.h"

using ::testing::_;

class TrafficLightTest : public ::testing::Test {
protected:
    MockLane* mockLane1;
    MockLane* mockLane2;
    MockLane* mockLane3;
    MockLane* mockLane4;
    TrafficLight* light;

    void SetUp() override {
        mockLane1 = new MockLane();
        mockLane2 = new MockLane();
        mockLane3 = new MockLane();
        mockLane4 = new MockLane();
        light = new TrafficLight(mockLane1, mockLane2, mockLane3, mockLane4);
    }

    void TearDown() override {
        delete light;
        delete mockLane1;
        delete mockLane2;
        delete mockLane3;
        delete mockLane4;
    }
};

TEST_F(TrafficLightTest, InitialStateIsRedForAllLanes) {
    EXPECT_CALL(*mockLane1, notify()).Times(::testing::AnyNumber());
    EXPECT_CALL(*mockLane2, notify()).Times(::testing::AnyNumber());
    EXPECT_CALL(*mockLane3, notify()).Times(::testing::AnyNumber());
    EXPECT_CALL(*mockLane4, notify()).Times(::testing::AnyNumber());
    EXPECT_EQ(light->getState(LANE_1), RED);
    EXPECT_EQ(light->getState(LANE_2), RED);
    EXPECT_EQ(light->getState(LANE_3), RED);
    EXPECT_EQ(light->getState(LANE_4), RED);
}

TEST_F(TrafficLightTest, SetStateChangesStateToGreen) {
    EXPECT_CALL(*mockLane1, notify()).Times(::testing::AnyNumber());
    EXPECT_CALL(*mockLane2, notify()).Times(::testing::AnyNumber());
    EXPECT_CALL(*mockLane3, notify()).Times(::testing::AnyNumber());
    EXPECT_CALL(*mockLane4, notify()).Times(::testing::AnyNumber());
    light->setState(LANE_1, GREEN);
    EXPECT_EQ(light->getState(LANE_1), GREEN);
}

TEST_F(TrafficLightTest, SetStateChangesStateToYellow) {
    EXPECT_CALL(*mockLane1, notify()).Times(::testing::AnyNumber());
    EXPECT_CALL(*mockLane2, notify()).Times(::testing::AnyNumber());
    EXPECT_CALL(*mockLane3, notify()).Times(::testing::AnyNumber());
    EXPECT_CALL(*mockLane4, notify()).Times(::testing::AnyNumber());
    light->setState(LANE_2, YELLOW);
    EXPECT_EQ(light->getState(LANE_2), YELLOW);
}

TEST_F(TrafficLightTest, SetStateChangesStateToRed) {
    EXPECT_CALL(*mockLane1, notify()).Times(::testing::AnyNumber());
    EXPECT_CALL(*mockLane2, notify()).Times(::testing::AnyNumber());
    EXPECT_CALL(*mockLane3, notify()).Times(::testing::AnyNumber());
    EXPECT_CALL(*mockLane4, notify()).Times(::testing::AnyNumber());
    light->setState(LANE_3, GREEN);
    light->setState(LANE_3, RED);
    EXPECT_EQ(light->getState(LANE_3), RED);
}

TEST_F(TrafficLightTest, SetStateGreenNotifiesCorrectLane) {
    EXPECT_CALL(*mockLane1, notify()).Times(1);
    EXPECT_CALL(*mockLane2, notify()).Times(::testing::AnyNumber());
    EXPECT_CALL(*mockLane3, notify()).Times(::testing::AnyNumber());
    EXPECT_CALL(*mockLane4, notify()).Times(::testing::AnyNumber());
    light->setState(LANE_1, GREEN);
}

TEST_F(TrafficLightTest, SetStateYellowDoesNotNotifyLane) {
    EXPECT_CALL(*mockLane1, notify()).Times(::testing::AnyNumber());
    EXPECT_CALL(*mockLane2, notify()).Times(0);
    EXPECT_CALL(*mockLane3, notify()).Times(::testing::AnyNumber());
    EXPECT_CALL(*mockLane4, notify()).Times(::testing::AnyNumber());
    light->setState(LANE_2, YELLOW);
}

TEST_F(TrafficLightTest, SetStateRedDoesNotNotifyLane) {
    EXPECT_CALL(*mockLane1, notify()).Times(::testing::AnyNumber());
    EXPECT_CALL(*mockLane2, notify()).Times(::testing::AnyNumber());
    EXPECT_CALL(*mockLane3, notify()).Times(0);
    EXPECT_CALL(*mockLane4, notify()).Times(::testing::AnyNumber());
    light->setState(LANE_3, RED);
}

TEST_F(TrafficLightTest, SetStateGreenOnlyNotifiesCorrectLane) {
    EXPECT_CALL(*mockLane1, notify()).Times(1);
    EXPECT_CALL(*mockLane2, notify()).Times(0);
    EXPECT_CALL(*mockLane3, notify()).Times(0);
    EXPECT_CALL(*mockLane4, notify()).Times(0);
    light->setState(LANE_1, GREEN);
}

TEST_F(TrafficLightTest, StatesAreIndependent) {
    EXPECT_CALL(*mockLane1, notify()).Times(::testing::AnyNumber());
    EXPECT_CALL(*mockLane2, notify()).Times(::testing::AnyNumber());
    EXPECT_CALL(*mockLane3, notify()).Times(::testing::AnyNumber());
    EXPECT_CALL(*mockLane4, notify()).Times(::testing::AnyNumber());
    light->setState(LANE_1, GREEN);
    light->setState(LANE_2, YELLOW);
    EXPECT_EQ(light->getState(LANE_1), GREEN);
    EXPECT_EQ(light->getState(LANE_2), YELLOW);
    EXPECT_EQ(light->getState(LANE_3), RED);
    EXPECT_EQ(light->getState(LANE_4), RED);
}
