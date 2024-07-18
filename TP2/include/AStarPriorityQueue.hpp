#ifndef ASTARPRIORITYQUEUE_HPP
#define ASTARPRIORITYQUEUE_HPP

#include <iostream>

// Classe utilizada para o bom funcionamento do algoritmo A*.
class AStarpqNode {
    public:
        AStarpqNode();              // Construtor sem parâmetros. Utilizado para iniciar o minHeap.
        AStarpqNode(int vertice, double distPercorrida, double heuristica, int portais);    // Construtor com parametros.
        int vertice;                // Vértice atual.
        double distPercorrida;      // Distância já percorrida.
        double heuristica;          // Heuristica: Distância euclidiana entre o vértice atual e o vértice de destino.
        double estimativa;          // distPercorrida + heuristica. Vai ser usado para ordenar o heap.
        int portaisUsados;          // Número de portais usados.
};

// minHeap para o algoritmo A*. Tem as mesmas funcionalidades que a usada para o Dijkstra.
// A única diferença é que este minHeap será ordenado pela estimativa.
class AStarPriorityQueue {
    public:
        AStarPriorityQueue(int maxsize);
        ~AStarPriorityQueue();
        void Inserir(int vertice, double distPercorrida, double heuristica, int portais);
        void Remover();
        AStarpqNode* Topo();
        bool Vazio();
        void ImprimirTopo();

    private:
        int GetAncestral(int posicao);
        int GetSucessorEsq(int posicao);
        int GetSucessorDir(int posicao);
        int tamanho;
        AStarpqNode* data;
};

#endif