# A-PathFinding-
Juego de demostracion de A* para la clase de IA, 

Este proyecto implementa el algoritmo de búsqueda A* (A-Star) utilizando C++ y SFML.

El programa representa un mapa mediante una cuadrícula de nodos. El algoritmo busca el camino desde un nodo inicial hasta un nodo objetivo, evitando los obstáculos existentes.

El proyecto también permite demostrar dos situaciones:

1. Un escenario donde existe un camino entre el inicio y el objetivo.
2. Un escenario donde no existe un camino debido a los obstáculos.
A* es un algoritmo de búsqueda de caminos que utiliza tres valores principales:

- **g:** costo real acumulado desde el nodo inicial hasta el nodo actual.
- **h:** estimación del costo desde el nodo actual hasta el objetivo.
- **f:** costo total estimado.

La fórmula utilizada es:

f(n) = g(n) + h(n)

Para este proyecto se utiliza la distancia Manhattan como función heurística:

h(n) = |x1 - x2| + |y1 - y2|

El algoritmo utiliza una lista abierta (`openList`) para los nodos pendientes de explorar y una lista cerrada (`closedList`) para los nodos que ya fueron procesados.

//Compilación

Para compilar el proyecto se utiliza:

g++ -std=c++17 src/main.cpp src/Grid.cpp src/AStar.cpp -Iinclude -o AStar $(pkg-config --cflags --libs sfml-graphics)

Ejecución

Antes de ejecutar el programa en GitHub Codespaces se utiliza una pantalla virtual mediante Xvfb.

export DISPLAY=:99

Después:

./AStar