#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>

#include "Grid.hpp"
#include "AStar.hpp"

int main() {

    // =========================
    // CONFIGURACIÓN
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
    // NODO INICIAL Y OBJETIVO
    // =========================

    Node* start =
        grid.getNode(1, 1);

    Node* goal =
        grid.getNode(18, 13);


    // =========================
    // ALGORITMO A*
    // =========================

    AStar astar(grid);


    // =========================
    // VARIABLES
    // =========================

    std::vector<Node*> path;


    // =========================
    // MAPA NORMAL
    // =========================

    auto mapaNormal = [&]() {

        // Limpiar obstáculos

        for (int y = 0; y < GRID_HEIGHT; y++) {

            for (int x = 0; x < GRID_WIDTH; x++) {

                grid.setObstacle(
                    x,
                    y,
                    false
                );
            }
        }


        // Crear algunos obstáculos

        grid.setObstacle(5, 5, true);
        grid.setObstacle(6, 5, true);
        grid.setObstacle(7, 5, true);


        // Calcular camino

        path =
            astar.findPath(
                start,
                goal
            );


        std::cout
            << "\n=== MAPA NORMAL ==="
            << std::endl;


        if (path.empty()) {

            std::cout
                << "No existe un camino."
                << std::endl;

        }
        else {

            std::cout
                << "Nodos en el camino: "
                << path.size()
                << std::endl;
        }
    };


    // =========================
    // MAPA BLOQUEADO
    // =========================

    auto mapaBloqueado = [&]() {

        // Limpiar obstáculos

        for (int y = 0; y < GRID_HEIGHT; y++) {

            for (int x = 0; x < GRID_WIDTH; x++) {

                grid.setObstacle(
                    x,
                    y,
                    false
                );
            }
        }


        // Crear pared vertical completa

        for (int y = 0; y < GRID_HEIGHT; y++) {

            grid.setObstacle(
                10,
                y,
                true
            );
        }


        // Calcular camino

        path =
            astar.findPath(
                start,
                goal
            );


        std::cout
            << "\n=== MAPA BLOQUEADO ==="
            << std::endl;


        if (path.empty()) {

            std::cout
                << "No existe un camino entre "
                << "el inicio y el objetivo."
                << std::endl;

        }
        else {

            std::cout
                << "Nodos en el camino: "
                << path.size()
                << std::endl;
        }
    };


    // =========================
    // MAPA INICIAL
    // =========================

    mapaNormal();


    std::cout << std::endl;

    std::cout
        << "Controles:"
        << std::endl;

    std::cout
        << "1 - Mapa normal"
        << std::endl;

    std::cout
        << "2 - Mapa bloqueado"
        << std::endl;

    std::cout
        << "ESC - Salir"
        << std::endl;


    // =========================
    // BUCLE PRINCIPAL
    // =========================

    while (window.isOpen()) {

        sf::Event event;

        while (window.pollEvent(event)) {


            // =========================
            // CERRAR VENTANA
            // =========================

            if (
                event.type ==
                sf::Event::Closed
            ) {

                window.close();
            }


            // =========================
            // TECLADO
            // =========================

            if (
                event.type ==
                sf::Event::KeyPressed
            ) {


                // MAPA NORMAL

                if (
                    event.key.code ==
                    sf::Keyboard::Num1
                ) {

                    mapaNormal();
                }


                // MAPA BLOQUEADO

                if (
                    event.key.code ==
                    sf::Keyboard::Num2
                ) {

                    mapaBloqueado();
                }


                // SALIR

                if (
                    event.key.code ==
                    sf::Keyboard::Escape
                ) {

                    window.close();
                }
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