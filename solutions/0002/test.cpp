#include <adjacent-products.hpp>
#include <gtest/gtest.h>
#include <algorithm>
#include <ranges>

TEST(AdjacentProducts, ResultValidation1)
{
    std::vector series{1,2,3,4,5};
    std::vector result = adjacent_products(series);

    EXPECT_EQ(std::ranges::equal(result, std::vector{120,60,40,30,24}), true);
}

TEST(AdjacentProducts, ResultValidation2)
{
    std::vector series{3,2,1};
    std::vector result = adjacent_products(series);

    EXPECT_EQ(std::ranges::equal(result, std::vector{2,3,6}), true);
}

TEST(AdjacentProducts, ZeroValidation)
{
    std::vector series{3,2,1,0};
    std::vector result = adjacent_products(series);

    EXPECT_EQ(std::ranges::equal(result, std::vector{0,0,0,6}), true);
}

TEST(AdjacentProducts, MultipleZeroValidation)
{
    std::vector series{0,3,2,1,0};
    std::vector result = adjacent_products(series);

    EXPECT_EQ(std::ranges::equal(result, std::vector(series.size(), 0)), true);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
