#include "Vertice.hpp"

// Construtor sem parâmetros.
Vertice::Vertice() {
    this->x = -1;
    this->y = -1;
}

// Construtor com parâmetros.
void Vertice::setCoord(int x, int y) {
    this->x = x;
    this->y = y;
}

// calcula a distância euclidiana entre dois vertices.
double Vertice::CalcularDistancia(Vertice* v) {
    int Dx = this->x - v->x; Dx *= Dx;
    int Dy = this->y - v->y; Dy *= Dy;
    return sqrt(Dy + Dx);
}