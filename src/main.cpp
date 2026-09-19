#include <SFML/Graphics.hpp>
#include <iostream>

int main() {

    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;

    sf::RenderWindow window(
        sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
        "A* Pathfinding - C++ SFML"
    );

    while (window.isOpen()) {

        sf::Event event;

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::White);

        window.display();
    }

    return 0;
}