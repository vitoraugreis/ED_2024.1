#include "graph.hpp"
#include <iostream>
#include <cstring>

int main(int argc, char* argv[]) {

    Grafo grafo = Grafo();
    int n; std::cin >> n;

    for (int i = 0; i<n; i++) {
        grafo.InsereVertice();
        int m; std::cin >> m;
        for (int j = 0; j<m; j++) {
            int dest; std::cin >> dest;
            grafo.InsereAresta(i, dest);
        }
    }

    if (strcmp(argv[1], "-d") == 0) {
        std::cout << grafo.QuantidadeVertices() << '\n';
        std::cout << grafo.QuantidadeArestas() << '\n';
        std::cout << grafo.GrauMinimo() << '\n';
        std::cout << grafo.GrauMaximo() << '\n';
    } else if (strcmp(argv[1], "-n") == 0) {
        for (int i = 0; i<n; i++) {
            grafo.ImprimeVizinhos(i);
        }
    } else {
        int vertices = grafo.QuantidadeVertices();
        int arestasCom = (vertices*(vertices-1)) / 2;
        if (grafo.QuantidadeArestas() == arestasCom) {
            std::cout << 1 << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }
    }

    return 0;
}