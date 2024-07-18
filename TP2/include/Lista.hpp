#ifndef LISTA_HPP
#define LISTA_HPP

#include <iostream>

// Classe No é usada para representar as arestas do grafo na lista de adjacência.
class No {
    public:
        No(int destino, double peso);
    private:
        int destino;    // Vértice final da aresta.
        double peso;    // Peso da aresta.
        No* prox;       // Próximo nó da lista.
    
    friend class Lista;
    friend class GrafoLA;
};

class Lista {
    public:
        Lista();
        void adicionarAresta(int destino, double peso);
        void imprimirLista();
    private:
        No* head;       // Nó cabeça da lista. Iniciado com nullptr.
    
    friend class GrafoLA;
};

#endif