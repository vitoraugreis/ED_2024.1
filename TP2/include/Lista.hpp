#ifndef LISTA_HPP
#define LISTA_HPP

#include <iostream>

class No {
    public:
        No(int destino, double peso);
    private:
        int destino;
        double peso;
        No* prox;
    
    friend class Lista;
};

class Lista {
    public:
        Lista();
        void adicionarAresta(int destino, double peso);
        void imprimirLista();
    private:
        No* head;
};

#endif