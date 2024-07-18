#ifndef ASTARPRIORITYQUEUE_HPP
#define ASTARPRIORITYQUEUE_HPP

#include <iostream>

class AStarpqNode {
    public:
        AStarpqNode();
        AStarpqNode(int vertice, double distPercorrida, double heuristica, int portais);
        int vertice;
        double distPercorrida;      // Distância já percorrida.
        double heuristica;          // Heuristica: Distância entre os vértices no plano.
        double peso;                // distPercorrida + heuristica. Vai ser usado para ordenar o heap.
        int portaisUsados;          // Número de portais usados.
};

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