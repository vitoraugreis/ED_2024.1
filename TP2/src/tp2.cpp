#include "GrafoLA.hpp"
#include "GrafoMA.hpp"
#include "Vertice.hpp"

int main() {
    int totalVertices, totalArestas, totalPortais;
    std::cin >> totalVertices >> totalArestas >> totalPortais;

    // Inicia o Grafo e o vetor de vértices.
    GrafoLA* grafo = new GrafoLA(totalVertices);
    Vertice* vertices = new Vertice[totalVertices];

    // Leitura de todas as coordenadas dos vértices.
    for (int i = 0; i<totalVertices; i++) {
        int x, y; 
        std::cin >> x >> y;
        vertices[i].setCoord(x, y);                                     // Método para atualizar as coordenadas dos vértices.
    }

    // Leitura das arestas.
    for (int i = 0; i<totalArestas; i++) {
        int v1, v2;
        std::cin >> v1 >> v2;
        double peso = vertices[v1].CalcularDistancia(&vertices[v2]);    // Calculo do peso das arestas.
        grafo->adicionarAresta(v1, v2, peso);                            // Adição das arestas no grafo.
    }

    // Leitura dos portais.
    for (int i = 0; i<totalPortais; i++) {
        int v1, v2;
        std::cin >> v1 >> v2;
        grafo->adicionarAresta(v1, v2, 0);                               // Adição do portal no grafo.
    }

    int energia, limUsoPortais;
    std::cin >> energia >> limUsoPortais;                               // Energia e a quantidade de portais que Linque pode usar.
    
    double menorCaminhoDijkstra = grafo->Dijkstra(0, totalVertices-1, limUsoPortais);        // Menor caminho encontrado por Dijkstra.
    double menorCaminhoAStar = grafo->AStar(0, totalVertices-1, vertices, limUsoPortais);    // Menor caminho encontrado por A*.

    // Verifica se Linque consegue atravessar a floresta com sua quantidade de energia (1) ou não (0).
    if (energia < menorCaminhoDijkstra || menorCaminhoDijkstra == INF) { std::cout << 0 << ' '; }
    else { std::cout << 1 << ' '; }

    if (energia < menorCaminhoAStar || menorCaminhoAStar == INF) { std::cout << 0 << std::endl; }
    else { std::cout << 1 << std::endl; }

    delete[] vertices;
    delete grafo;
    return 0;
}