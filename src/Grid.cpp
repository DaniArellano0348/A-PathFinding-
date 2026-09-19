#include "Grid.hpp"
#include <algorithm>
#include <limits>

Grid::Grid(int width, int height)
    : width(width), height(height) {

    nodes.resize(height);

    for (int y = 0; y < height; y++) {

        nodes[y].resize(width);

        for (int x = 0; x < width; x++) {

            nodes[y][x].x = x;
            nodes[y][x].y = y;

            // Valores iniciales para A*
            nodes[y][x].g =
                std::numeric_limits<float>::infinity();

            nodes[y][x].h = 0;

            nodes[y][x].f =
                std::numeric_limits<float>::infinity();

            nodes[y][x].obstacle = false;

            nodes[y][x].parent = nullptr;
        }
    }
}

Node* Grid::getNode(int x, int y) {

    if (x < 0 || x >= width ||
        y < 0 || y >= height) {

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

void Grid::setObstacle(int x, int y, bool obstacle) {

    Node* node = getNode(x, y);

    if (node != nullptr) {
        node->obstacle = obstacle;
    }
}

void Grid::draw(
    sf::RenderWindow& window,
    float cellSize,
    Node* start,
    Node* goal,
    const std::vector<Node*>& path
) {

    sf::RectangleShape cell;

    cell.setSize(
        sf::Vector2f(
            cellSize - 1,
            cellSize - 1
        )
    );

    for (int y = 0; y < height; y++) {

        for (int x = 0; x < width; x++) {

            cell.setPosition(
                x * cellSize,
                y * cellSize
            );

            Node* node = &nodes[y][x];

            // Nodo inicial
            if (node == start) {

                cell.setFillColor(
                    sf::Color::Green
                );
            }

            // Nodo objetivo
            else if (node == goal) {

                cell.setFillColor(
                    sf::Color::Red
                );
            }

            // Obstáculos
            else if (node->obstacle) {

                cell.setFillColor(
                    sf::Color::Black
                );
            }

            // Camino encontrado por A*
            else if (
                std::find(
                    path.begin(),
                    path.end(),
                    node
                ) != path.end()
            ) {

                cell.setFillColor(
                    sf::Color::Blue
                );
            }

            // Celda normal
            else {

                cell.setFillColor(
                    sf::Color::White
                );
            }

            window.draw(cell);
        }
    }
}