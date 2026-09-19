#ifndef ASTAR_HPP
#define ASTAR_HPP

#include <vector>

#include "Node.hpp"
#include "Grid.hpp"

class AStar {

private:

    Grid& grid;

    float heuristic(
        Node* a,
        Node* b
    );

    std::vector<Node*> getNeighbors(
        Node* node
    );

public:

    AStar(Grid& grid);

    std::vector<Node*> findPath(
        Node* start,
        Node* goal
    );
};

#endif