#pragma once

#include <set>
#include <ranges>
#include <algorithm>

/*
 * Given a list of numbers and a number `k`,
 * return whether any two numbers from the list add up to `k`.
 *
 * For example, given `[10, 15, 3, 7]` and `k` of 17,
 * return true since 10 + 7 is 17.
 *
 * Bonus: Can you do this in one pass?
 *
 */
template <typename C, typename T>
constexpr bool ksum(C const& container, T const& k)
{
    std::set<T> seen{};

    auto contains_ksum = [&seen, &k](T const& element) {
        bool contains = seen.contains(k - element);
        seen.insert(element);
        return contains;
    };

    return std::ranges::any_of(container, contains_ksum);
}
