#ifndef GRAFOLA_HPP
#define GRAFOLA_HPP

#include "Lista.hpp"
#include <iostream>

class GrafoLA {
    public:
        GrafoLA(int numVertices);
        void adicionarAresta(int origem, int destino, double peso);
        void imprimirGrafo();
    private:
        int numVertices;
        Lista* listaAdj;
};

#endif
