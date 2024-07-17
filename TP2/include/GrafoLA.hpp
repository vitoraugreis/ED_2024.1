#ifndef GRAFOLA_HPP
#define GRAFOLA_HPP

#include "Lista.hpp"
#include "PriorityQueue.hpp"
#include <iostream>
#define INF 10000000

class GrafoLA {
    public:
        GrafoLA(int numVertices);
        void adicionarAresta(int origem, int destino, double peso);
        void imprimirGrafo();
        double Dijkstra(int origem, int destino, int limitePortais);
    private:
        int numVertices;
        Lista* listaAdj;
};

#endif
