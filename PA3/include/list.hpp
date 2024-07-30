#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

class Celula {
    public:
        Celula();

    private:
        int valor;
        Celula* prox;
    
    friend class ListaEncadeada;
};

class ListaEncadeada {
    public:
        ListaEncadeada();
        ~ListaEncadeada();

        void InsereFinal(int valor);
        void Imprime();
        void Limpa();
        int getTamanho();


    private:
        Celula* primeiro;
        Celula* ultimo;
        int tamanho;

    friend class ListaAdjacencia;
};

#endif