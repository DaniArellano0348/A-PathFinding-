#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>

#include "Grid.hpp"
#include "AStar.hpp"

int main() {

    // =========================
    // CONFIGURACIÓN DE VENTANA
    // =========================

    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;

    const int GRID_WIDTH = 20;
    const int GRID_HEIGHT = 15;

    const float CELL_SIZE = 40.0f;


    // =========================
    // CREAR VENTANA
    // =========================

    sf::RenderWindow window(
        sf::VideoMode(
            WINDOW_WIDTH,
            WINDOW_HEIGHT
        ),
        "A* Pathfinding - SFML"
    );


    // =========================
    // CREAR GRID
    // =========================

    Grid grid(
        GRID_WIDTH,
        GRID_HEIGHT
    );


    // =========================
    // NODO INICIAL Y FINAL
    // =========================

    Node* start =
        grid.getNode(1, 1);

    Node* goal =
        grid.getNode(18, 13);


    // =========================
    // CREAR OBSTÁCULOS
    // =========================

    grid.setObstacle(
        5, 5, true
    );

    grid.setObstacle(
        6, 5, true
    );

    grid.setObstacle(
        7, 5, true
    );


    // =========================
    // EJECUTAR A*
    // =========================

    AStar astar(grid);

    std::vector<Node*> path =
        astar.findPath(
            start,
            goal
        );


    // =========================
    // MOSTRAR RESULTADO
    // =========================

    std::cout
        << "Nodos en el camino: "
        << path.size()
        << std::endl;


    std::cout
        << "Camino: ";

    for (Node* node : path) {

        std::cout
            << "("
            << node->x
            << ","
            << node->y
            << ") ";
    }

    std::cout << std::endl;


    // =========================
    // BUCLE PRINCIPAL
    // =========================

    while (window.isOpen()) {

        sf::Event event;

        while (
            window.pollEvent(event)
        ) {

            if (
                event.type ==
                sf::Event::Closed
            ) {

                window.close();
            }
        }


        // =========================
        // DIBUJAR
        // =========================

        window.clear(
            sf::Color::White
        );

        grid.draw(
            window,
            CELL_SIZE,
            start,
            goal,
            path
        );

        window.display();
    }

    return 0;
}