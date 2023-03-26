#pragma once

#include <algorithm>
#include <ranges>
#include <vector>

/*
 * Given an array of integers, return a new array such that each element at index i
 * of the new array is the product of all the numbers in the original array except
 * the one at i.
 *
 * For example, if our input was [1, 2, 3, 4, 5], the expected output would be
 * [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be
 * [2, 3, 6].
 *
 * Follow-up: what if you can't use division?
 *
 */

template <typename T>
std::vector<T> adjacent_products(std::vector<T> const& numbers)
{
    T total{1};
    std::size_t zeros{};
    std::vector<T> results{};
    results.reserve(numbers.size());

    auto product = [&total, &zeros](T const& item) {
        if (item == 0)
            zeros++;
        else
            total *= item;
    };

    // Having multiple zeros in input range unconditionally zeros out output range.
    // Single zero within input range results all adjacent items to be zero but itself.
    // No zero within input range results normal production of adjacents.
    auto divide = [&total, &zeros](T const& item) {
        return zeros > 1 ? 0 : (item == 0 ? total : (zeros == 1 ? 0 : total / item));
    };

    std::ranges::for_each(numbers, product);
    std::ranges::copy(numbers, std::back_inserter(results));
    std::ranges::transform(numbers, std::begin(results), divide);
    return results;
}
