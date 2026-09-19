#include "AStar.hpp"

#include <cmath>
#include <algorithm>

AStar::AStar(Grid& grid)
    : grid(grid) {
}

float AStar::heuristic(
    Node* a,
    Node* b
) {

    return std::abs(a->x - b->x)
         + std::abs(a->y - b->y);
}

std::vector<Node*> AStar::getNeighbors(
    Node* node
) {

    std::vector<Node*> neighbors;

    const int directions[4][2] = {

        { 1, 0 },
        {-1, 0 },
        { 0, 1 },
        { 0,-1 }
    };

    for (const auto& direction : directions) {

        int newX =
            node->x + direction[0];

        int newY =
            node->y + direction[1];

        Node* neighbor =
            grid.getNode(newX, newY);

        // Fuera de la cuadrícula
        if (neighbor == nullptr) {
            continue;
        }

        // No podemos atravesar obstáculos
        if (neighbor->obstacle) {
            continue;
        }

        neighbors.push_back(neighbor);
    }

    return neighbors;
}

std::vector<Node*> AStar::findPath(
    Node* start,
    Node* goal
) {

    std::vector<Node*> path;

    std::vector<Node*> openList;

    std::vector<Node*> closedList;

    // Configurar nodo inicial
    start->g = 0;

    start->h =
        heuristic(start, goal);

    start->f =
        start->g + start->h;

    start->parent = nullptr;

    openList.push_back(start);

    while (!openList.empty()) {

        // Tomamos inicialmente el primer nodo
        Node* current = openList[0];

        // Buscamos el nodo con menor f
        for (Node* node : openList) {

            if (node->f < current->f) {

                current = node;
            }
        }

        // ¿Llegamos al objetivo?
        if (current == goal) {

            Node* node = goal;

            // Reconstruir camino
            while (node != nullptr) {

                path.push_back(node);

                node = node->parent;
            }

            // Invertir para tener
            // inicio -> objetivo
            std::reverse(
                path.begin(),
                path.end()
            );

            return path;
        }

        // Sacar current de openList
        openList.erase(
            std::remove(
                openList.begin(),
                openList.end(),
                current
            ),
            openList.end()
        );

        // Agregar a cerrados
        closedList.push_back(current);

        // Revisar vecinos
        for (
            Node* neighbor :
            getNeighbors(current)
        ) {

            // Si ya fue procesado
            if (
                std::find(
                    closedList.begin(),
                    closedList.end(),
                    neighbor
                ) != closedList.end()
            ) {

                continue;
            }

            // Costo de movernos al vecino
            float tentativeG =
                current->g + 1;

            auto openIt =
                std::find(
                    openList.begin(),
                    openList.end(),
                    neighbor
                );

            // Si encontramos una mejor ruta
            if (
                openIt == openList.end() ||
                tentativeG < neighbor->g
            ) {

                neighbor->parent =
                    current;

                neighbor->g =
                    tentativeG;

                neighbor->h =
                    heuristic(
                        neighbor,
                        goal
                    );

                neighbor->f =
                    neighbor->g +
                    neighbor->h;

                // Agregar a openList
                if (
                    openIt == openList.end()
                ) {

                    openList.push_back(
                        neighbor
                    );
                }
            }
        }
    }

    // No existe camino
    return path;
}