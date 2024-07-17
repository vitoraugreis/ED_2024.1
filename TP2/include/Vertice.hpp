#ifndef VERTICE_HPP
#define VERTICE_HPP

#include <cmath>

class Vertice {
    public:
        Vertice();
        void setCoord(int x, int y);
        double CalcularDistancia(Vertice* v);
    private:
        int x, y;
};

#endif