#pragma once

#include <iostream>
#include <set>
#include <ranges>
#include <iterator>
#include <algorithm>

/*
 * Given a list of numbers and a number `k`,
 * return whether any two numbers from the list add up to `k`.
 *
 * For example, given `[10, 15, 3, 7]` and `k` of 17,
 * return true since 10 + 7 is 17.
 *
 * Bonus: Can you do this in one pass?
 */

template <typename C, typename T>
constexpr bool ksum(C const& container, T summation)
{
    std::set<T> seen{};

    for (auto iter = std::cbegin(container); iter != std::cend(container); ++iter)
    {
        if (seen.contains(summation - *iter))
            return true;

        seen.insert(*iter);
    }

    return false;
}
