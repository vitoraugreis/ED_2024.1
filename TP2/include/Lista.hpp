// Lista utilizando alocação encadeada
// Tamanho máximo da estrutura não fixo.

#ifndef LISTA_HPP
#define LISTA_HPP

#include <iostream>

class Grafo;

class Item {
    public:
        Item();

    private:
        int idVertice;
        double peso;

    friend class Lista;
};

class Celula {
    public:
        Celula();
    
    private:
        Item item;
        Celula* prox;
    
    friend class Lista;
};

class Lista {
    public:
        Lista();
        ~Lista();

        void Insere(int id, double peso);
        bool Pesquisa(int idVertice);
        void Limpa();
        bool Vazia();
        void Imprime();

    private:
        int idVertice;
        Celula* primeiro;
        Celula* ultimo;

    friend class Grafo;
};

#endif