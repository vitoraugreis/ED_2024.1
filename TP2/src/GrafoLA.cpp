#include "GrafoLA.hpp"

GrafoLA::GrafoLA(int numVertices) {
    this->numVertices = numVertices;
    this->listaAdj = new Lista[numVertices];
}

void GrafoLA::adicionarAresta(int origme, int destino, double peso) {
    listaAdj[origme].adicionarAresta(destino, peso);
}

void GrafoLA::imprimirGrafo() {
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "Vértice " << i << ":";
        listaAdj[i].imprimirLista();
        std::cout << std::endl;
    }
}