#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include <iostream>

class pqNode {
    public:
        pqNode();
        pqNode(int vertice, double peso, int portais);
        int vertice;
        double peso;
        int portaisUsados;
};

class PriorityQueue {
    public:
        PriorityQueue(int maxsize);
        ~PriorityQueue();
        void Inserir(int vertice, double peso, int portais);
        void Remover();
        pqNode* Topo();
        bool Vazio();
        void ImprimirTopo();

    private:
        int GetAncestral(int posicao);
        int GetSucessorEsq(int posicao);
        int GetSucessorDir(int posicao);
        int tamanho;
        pqNode* data;
};

#endif