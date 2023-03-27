#pragma once

class Node
{
};

class Serialize
{
    std::string serialize(Node const&);
    Node deserialize(std::string const&);
};
