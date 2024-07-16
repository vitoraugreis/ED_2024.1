// Grafo usando lista de adjacência
#ifndef GRAFOLA_HPP
#define GRAFOLA_HPP

#include "Lista.hpp"
#include <iostream>
#include <cmath>
#define INF 0x3f3f3f3f

class Lista;

class Vertice {
    public:
        Vertice();
        void SetId(int id);
        void SetCoords(int x, int y);
    private:
        int id, x, y;
        Lista* vizinhos;
    
    friend class Grafo;
};

class Grafo {
    public:
        Grafo(int numVertices, int numArestas);
        ~Grafo();
        void AtualizaVertice(int id, int x, int y);
        void InsereAresta(int v1, int v2);
        void InsereArestaSemPeso(int v1, int v2);
        bool ExisteAresta(int v1, int v2);
        bool ListaAdjVazia();
        void ImprimeGrafo();
        double Dijkstra();

    private:
        int numVertices;
        int numArestas;
        Vertice* listaAdj;
        double CalcularPeso(int x1, int x2, int y1, int y2);
};

#endif