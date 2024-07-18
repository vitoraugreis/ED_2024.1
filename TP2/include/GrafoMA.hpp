#ifndef GRAFOMA_HPP
#define GRAFOMA_HPP

#include "Lista.hpp"
#include "PriorityQueue.hpp"
#include "AStarPriorityQueue.hpp"
#include "Vertice.hpp"
#include <iostream>
#define INF 10000000

class GrafoMA {
    public:
        GrafoMA(int numVertices);
        ~GrafoMA();
        void adicionarAresta(int origem, int destino, double peso);
        void imprimirGrafo();
        double Dijkstra(int origem, int destino, int limitePortais);
        double AStar(int origem, int destino, Vertice* vertices, int limitePortais);
    private:
        int numVertices;
        double** matrizAdj;
};

#endif