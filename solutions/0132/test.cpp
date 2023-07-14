#include <gtest/gtest.h>
#include <hitcounter.hpp>
#include <chrono>

TEST(HitCounterTest, RecordTotal)
{
    HitCounter counter;
    counter.record(std::chrono::system_clock::now());
    EXPECT_EQ(counter.total(), 1);
}

TEST(HitCounterTest, Range)
{
    HitCounter counter;
    timestamp_t present = std::chrono::system_clock::now();
    timestamp_t past = present - std::chrono::seconds{10};
    timestamp_t later = present + std::chrono::seconds{10};

    counter.record(present);
    EXPECT_EQ(counter.range(past, later), 1);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
