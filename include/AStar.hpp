#ifndef ASTAR_HPP
#define ASTAR_HPP

#include <vector>
#include "Node.hpp"

class AStar {
public:
    std::vector<Node*> findPath(Node* start, Node* goal);
};

#endif