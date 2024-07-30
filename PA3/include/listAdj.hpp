#ifndef LISTADJ_HPP
#define LISTADJ_HPP

#include "list.hpp"

class ListaAdjacencia {
    public:
        ListaAdjacencia();
        ~ListaAdjacencia();

        void InsereVertice();
        void InsereAresta(int inicio, int destino);
        int TamanhoTotal();
        int MenorLista();
        int MaiorLista();
        void ImprimeIndividual(int x);

    private:
        ListaEncadeada* lista;
        int limite;
        int numVertices;
        void Redimensionar();

    friend class Grafo;
};

#endif