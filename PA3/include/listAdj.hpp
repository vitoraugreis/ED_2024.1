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
        ListaEncadeada* Procurar(int x);
        void Imprime();
        void Limpa();

    private:
        ListaEncadeada* primeiro;
        ListaEncadeada* ultimo;
        int numVertices;

    friend class Grafo;
};

#endif