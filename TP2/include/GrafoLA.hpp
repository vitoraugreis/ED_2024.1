#ifndef GRAFOLA_HPP
#define GRAFOLA_HPP

#include "Lista.hpp"
#include "PriorityQueue.hpp"
#include "AStarPriorityQueue.hpp"
#include "Vertice.hpp"
#include <iostream>
#define INF 10000000

class GrafoLA {
    public:
        GrafoLA(int numVertices);
        ~GrafoLA();
        void adicionarAresta(int origem, int destino, double peso);                     // Adiciona aresta no grafo
        void imprimirGrafo();
        double Dijkstra(int origem, int destino, int limitePortais);                    // Dijkstra
        double AStar(int origem, int destino, Vertice* vertices, int limitePortais);    // Algoritmo A*
    private:
        int numVertices;        // Número de vértices do grafo.
        Lista* listaAdj;        // Lista de adjacência do grafo.
};

#endif
