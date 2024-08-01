#ifndef MINHEAP_HPP
#define MINHEAP_HPP

#include "unionFind.hpp"
#include <iostream>

class MinHeap {
    public:
        MinHeap(int tamanho);
        ~MinHeap();

        void Inserir(int u, int v, int peso);
        Aresta Remover();
        bool Vazio();
        void ImprimirTopo();

    private:
        int GetAncestral(int posicao);
        int GetSucessorEsq(int posicao);
        int GetSucessorDir(int posicao);
        void heapifyUp(int pos);
        void heapifyDown(int pos); 
        int tamanho;
        Aresta* data;
};

#endif