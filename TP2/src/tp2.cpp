#include "GrafoLA.hpp"
#include <iostream>

using namespace std;

int main() {
    int totalVertices, totalArestas, totalPortais;
    cin >> totalVertices >> totalArestas >> totalPortais;

    Grafo grafo = Grafo(totalVertices, totalArestas+totalPortais);

    for (int i = 0; i<totalVertices; i++) {
        int x, y; 
        cin >> x >> y;
        grafo.AtualizaVertice(i, x, y);
    }

    for (int i = 0; i<totalArestas; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        grafo.InsereAresta(v1, v2);
    }

    for (int i = 0; i<totalPortais; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        grafo.InsereArestaSemPeso(v1, v2);
    }

    int energia, limUsoPortais;
    cin >> energia >> limUsoPortais; // energia e a quantidade de portais que Linque pode usar.
    grafo.ImprimeGrafo();
}