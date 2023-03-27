# Problem #3 (Not Solved)

Given the root to a binary tree, implement `serialize(root)`, which serializes the tree into a string, and `deserialize(s)`, which deserializes the string back into the tree.

For example, given the following `Node` class:

```py
class Node:
    def __init__(self, val, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right
```

The following test should pass:

```py
node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left'
```

## Solutions

* [serialize header](/solutions/0003/serialize.hpp)
* [test](/solutions/0003/test.cpp)

## Usage

```sh
cmake -S . -B build -D CMAKE_BUILD_TYPE=release
cmake --build build --parallel --target serialize
./build/serialize -l 10 -l 15 -l 3 -l 7 -k 17
```

## Test

```sh
cmake -S . -B build -D CMAKE_BUILD_TYPE=release
cmake --build build --parallel --target serialize-test
./build/serialize-test
```
