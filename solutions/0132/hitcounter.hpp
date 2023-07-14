#include <algorithm>
#include <ranges>
#include <chrono>
#include <vector>

using timestamp_t = std::chrono::time_point<std::chrono::system_clock>;

struct Hit
{
    timestamp_t timestamp;
    Hit(timestamp_t const& timestamp): timestamp{timestamp} {}
};

struct hit_predicate
{
    const timestamp_t lower, upper;
    hit_predicate(timestamp_t const& lower, timestamp_t const& upper): lower{lower}, upper{upper} {}

    bool operator()(Hit const& hit)
    {
        return hit.timestamp >= lower && hit.timestamp <= upper;
    }
};

class HitCounter
{
public:
    void record(timestamp_t timestamp)
    {
        hits.push_back(std::move(timestamp));
    }

    std::size_t total()
    {
        return hits.size();
    }

    std::size_t range(timestamp_t const& lower, timestamp_t const& upper)
    {
        return std::ranges::count_if(hits, hit_predicate{lower, upper});
    }

private:
    std::vector<Hit> hits;
};

