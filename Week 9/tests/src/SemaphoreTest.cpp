#include <gtest/gtest.h>
#include "Semaphore.h"
#include <thread>

class SemaphoreTest : public ::testing::Test {
protected:
    Semaphore* semaphore;

    void SetUp() override {
        semaphore = new Semaphore(3);
    }

    void TearDown() override {
        delete semaphore;
    }
};

TEST_F(SemaphoreTest, InitialCountIsCorrect) {
    EXPECT_EQ(semaphore->getCount(), 3);
}

TEST_F(SemaphoreTest, AcquireDecrementsCount) {
    semaphore->acquire();
    EXPECT_EQ(semaphore->getCount(), 2);
}

TEST_F(SemaphoreTest, ReleaseIncrementsCount) {
    semaphore->acquire();
    semaphore->release();
    EXPECT_EQ(semaphore->getCount(), 3);
}

TEST_F(SemaphoreTest, MultipleAcquiresDecrementCount) {
    semaphore->acquire();
    semaphore->acquire();
    semaphore->acquire();
    EXPECT_EQ(semaphore->getCount(), 0);
}

TEST_F(SemaphoreTest, AcquireBlocksWhenCountIsZero) {
    semaphore->acquire();
    semaphore->acquire();
    semaphore->acquire();

    bool acquired = false;
    std::thread t([&]() {
        semaphore->acquire();
        acquired = true;
    });

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    EXPECT_FALSE(acquired);

    semaphore->release();
    t.join();
    EXPECT_TRUE(acquired);
}

TEST_F(SemaphoreTest, ReleaseUnblocksWaitingThread) {
    semaphore->acquire();
    semaphore->acquire();
    semaphore->acquire();

    bool unblocked = false;
    std::thread t([semaphore = semaphore, &unblocked]() {
        semaphore->acquire();
        unblocked = true;
        semaphore->release();
    });

    semaphore->release();
    t.join();
    EXPECT_TRUE(unblocked);
}
