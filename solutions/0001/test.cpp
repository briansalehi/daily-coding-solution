#include <ksum.hpp>
#include <gtest/gtest.h>

#include <vector>

TEST(Ksum, KsumIntegral)
{
    std::vector<int> numbers{10, 15, 3, 7};

    EXPECT_EQ(ksum(numbers, 17), true);
    EXPECT_EQ(ksum(numbers, 10), true);
    EXPECT_EQ(ksum(numbers, 25), true);
}

TEST(Ksum, NotKsumIntegral)
{
    std::vector<int> numbers{10, 15, 3, 7};

    EXPECT_EQ(ksum(numbers, 8), false);
    EXPECT_EQ(ksum(numbers, 19), false);
    EXPECT_EQ(ksum(numbers, 23), false);
}

TEST(Ksum, KsumFloatingPoint)
{
    std::vector<double> numbers{10.2, 15.4, 3.2, 7.3};

    EXPECT_EQ(ksum(numbers, 17.5), true);
    EXPECT_EQ(ksum(numbers, 13.4), true);
    EXPECT_EQ(ksum(numbers, 10.5), true);
}

TEST(Ksum, NotKsumFloatingPoint)
{
    std::vector<double> numbers{10.2, 15.4, 3.2, 7.3};

    EXPECT_EQ(ksum(numbers, 19.5), false);
    EXPECT_EQ(ksum(numbers, 12.1), false);
    EXPECT_EQ(ksum(numbers, 1.4), false);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
