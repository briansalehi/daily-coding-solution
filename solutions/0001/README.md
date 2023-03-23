# Problem #1

Given a list of numbers and a number `k`, return whether any two numbers from the list add up to `k`.

For example, given `[10, 15, 3, 7]` and `k` of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?

## Solutions

This solution is named **Ksum** which refers to the question if two numbers add up to k.

* [ksum header](/solutions/0001/ksum.hpp)
* [usage](/solutions/0001/main.cpp)
* [test](/solutions/0001/test.cpp)

### Brute Force

The first obvious solution that comes to mind is brute force.  
For any `N` items in the list, there should be `N` look-ups through the list,
resulting the solution to take `O(N²)`, which is far from ideal.

### Linear Search

One more ideal solution would be to find summation to `k` in one pass so that it
takes `O(N)` in the worst case scenario when no two numbers could add up to `k`.

To solve, we should use a set container in order to remember the numbers we've seen.  
On each iteration existance of the difference of `k` and `number` is checked in the set.  
Any match would break the loop and function returns true.

My solution features C++ specific coding techniques such as [Templates][1], [Iterators][2],
and [Ranges][3].

[1]: https://en.cppreference.com/w/cpp/language/templates
[2]: https://en.cppreference.com/w/cpp/iterator
[3]: https://en.cppreference.com/w/cpp/ranges

## Usage

```sh
cmake -S . -B build -D CMAKE_BUILD_TYPE=release
cmake --build build --parallel --target problem
./build/problem -l 10 -l 15 -l 3 -l 7 -k 17
```

## Test

```sh
cmake -S . -B build -D CMAKE_BUILD_TYPE=release
cmake --build build --parallel --target ksum-test
./build/ksum-test
```
