#include "Grid.hpp"

Grid::Grid(int width, int height)
    : width(width), height(height) {

    nodes.resize(height);

    for (int y = 0; y < height; y++) {
        nodes[y].resize(width);

        for (int x = 0; x < width; x++) {
            nodes[y][x].x = x;
            nodes[y][x].y = y;

            nodes[y][x].g = 0;
            nodes[y][x].h = 0;
            nodes[y][x].f = 0;

            nodes[y][x].obstacle = false;
            nodes[y][x].parent = nullptr;
        }
    }
}

Node* Grid::getNode(int x, int y) {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        return nullptr;
    }

    return &nodes[y][x];
}

int Grid::getWidth() const {
    return width;
}

int Grid::getHeight() const {
    return height;
}