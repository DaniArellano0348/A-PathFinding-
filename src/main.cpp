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
    // CREAR OBSTÁCULOS INICIALES
    // =========================

    grid.setObstacle(5, 5, true);
    grid.setObstacle(6, 5, true);
    grid.setObstacle(7, 5, true);


    // =========================
    // CREAR ALGORITMO A*
    // =========================

    AStar astar(grid);


    // =========================
    // CALCULAR CAMINO INICIAL
    // =========================

    std::vector<Node*> path =
        astar.findPath(
            start,
            goal
        );


    std::cout
        << "Nodos en el camino: "
        << path.size()
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
            // CLIC DEL MOUSE
            // =========================

            if (
                event.type ==
                sf::Event::MouseButtonPressed
            ) {

                if (
                    event.mouseButton.button ==
                    sf::Mouse::Left
                ) {

                    // Posición del mouse
                    int mouseX =
                        event.mouseButton.x;

                    int mouseY =
                        event.mouseButton.y;


                    // Convertir píxeles
                    // a coordenadas del grid
                    int gridX =
                        static_cast<int>(
                            mouseX / CELL_SIZE
                        );

                    int gridY =
                        static_cast<int>(
                            mouseY / CELL_SIZE
                        );


                    // Obtener nodo seleccionado
                    Node* selectedNode =
                        grid.getNode(
                            gridX,
                            gridY
                        );


                    // Verificar que exista
                    if (
                        selectedNode != nullptr
                    ) {

                        // No permitir colocar
                        // obstáculos en inicio
                        // o objetivo
                        if (
                            selectedNode != start &&
                            selectedNode != goal
                        ) {

                            // Cambiar estado
                            bool newState =
                                !selectedNode->obstacle;

                            grid.setObstacle(
                                gridX,
                                gridY,
                                newState
                            );


                            // Recalcular A*
                            path =
                                astar.findPath(
                                    start,
                                    goal
                                );


                            // Mostrar resultado
                            std::cout
                                << "Nodos en el camino: "
                                << path.size()
                                << std::endl;
                        }
                    }
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