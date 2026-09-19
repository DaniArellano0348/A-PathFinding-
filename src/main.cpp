#include <SFML/Graphics.hpp>
#include "Grid.hpp"

int main() {

    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;

    const int GRID_WIDTH = 20;
    const int GRID_HEIGHT = 15;

    const float CELL_SIZE = 40.0f;

    sf::RenderWindow window(
        sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
        "A* Pathfinding - SFML"
    );

    Grid grid(GRID_WIDTH, GRID_HEIGHT);

    while (window.isOpen()) {

        sf::Event event;

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::White);

        grid.draw(window, CELL_SIZE);

        window.display();
    }

    return 0;
}