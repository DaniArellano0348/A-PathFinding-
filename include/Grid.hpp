#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
#include "Node.hpp"

class Grid {
private:
    int width;
    int height;

    std::vector<std::vector<Node>> nodes;

public:
    Grid(int width, int height);

    Node* getNode(int x, int y);

    int getWidth() const;
    int getHeight() const;
};

#endif