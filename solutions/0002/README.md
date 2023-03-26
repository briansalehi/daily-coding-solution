# Problem #2

Given an array of integers, return a new array such that each element at index `i`
of the new array is the product of all the numbers in the original array except
the one at `i`.

For example, if our input was `[1, 2, 3, 4, 5]`, the expected output would be
`[120, 60, 40, 30, 24]`. If our input was `[3, 2, 1]`, the expected output would be
`[2, 3, 6]`.

**Follow-up:** what if you can't use division?

## Solution

The solution is named **product** as the question requires an algorithm which returns
a list of product numbers.

* [product header](/solutions/0002/product.hpp)
* [usage](/solutions/0002/main.cpp)
* [test](/solutions/0002/test.cpp)

### Brute Force

The first solution is brute force but this is not an opmitized solution.  
For each item in the list the whole list should be iterated resulting in
efficiency of O(N²).

### Linear

This solution can be solved linearly by first iterating through the list and
finding the production of all items, then create an array holding as items as
the list contains each having value of production. Then iterate through the
generated list and set each value divided by value at that index in the list.

## Usage

```sh
cmake -S . -B build -D CMAKE_BUILD_TYPE=release
cmake --build build --parallel --target all
./build/product
```

## Test

```sh
cmake -S . -B build -D CMAKE_BUILD_TYPE=release
cmake --build build --parallel --target product-test
./build/product-test
```
