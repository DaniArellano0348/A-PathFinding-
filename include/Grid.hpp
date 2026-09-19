#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
#include <SFML/Graphics.hpp>
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

    void setObstacle(int x, int y, bool obstacle);

    void draw(
        sf::RenderWindow& window,
        float cellSize,
        Node* start,
        Node* goal,
        const std::vector<Node*>& path
    );
};

#endif