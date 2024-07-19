#ifndef VERTICE_HPP
#define VERTICE_HPP

#include <cmath>

class Vertice {
    public:
        Vertice();
        void setCoord(int x, int y);            // Atualiza as coordenadas do vértice.
        double CalcularDistancia(Vertice* v);   // Calcula a distância euclidiana de dois vértices.
    private:
        int x, y;
};

#endif