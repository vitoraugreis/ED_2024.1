#include "GrafoLA.hpp"
#include "Vertice.hpp"

int main() {
    int totalVertices, totalArestas, totalPortais;
    std::cin >> totalVertices >> totalArestas >> totalPortais;

    GrafoLA grafo = GrafoLA(totalVertices);
    Vertice* vertices = new Vertice[totalVertices];

    for (int i = 0; i<totalVertices; i++) {
        int x, y; 
        std::cin >> x >> y;
        vertices[i].setCoord(x, y);
    }

    for (int i = 0; i<totalArestas; i++) {
        int v1, v2;
        std::cin >> v1 >> v2;
        double peso = vertices[v1].CalcularDistancia(&vertices[v2]);
        grafo.adicionarAresta(v1, v2, peso);
    }

    for (int i = 0; i<totalPortais; i++) {
        int v1, v2;
        std::cin >> v1 >> v2;
        grafo.adicionarAresta(v1, v2, 0);
    }

    int energia, limUsoPortais;
    std::cin >> energia >> limUsoPortais; // energia e a quantidade de portais que Linque pode usar.
    grafo.imprimirGrafo();
    std::cout << grafo.Dijkstra(0, 0) << std::endl;
    std::cout << grafo.Dijkstra(0, 1) << std::endl;
    std::cout << grafo.Dijkstra(0, 2) << std::endl;
    std::cout << grafo.Dijkstra(0, 3) << std::endl;
    std::cout << grafo.Dijkstra(0, 4) << std::endl;
}