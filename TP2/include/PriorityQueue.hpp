#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

class pqNode {
    public:
        pqNode();
        pqNode(int vertice, double peso);
        int vertice;
        double peso;
};

class PriorityQueue {
    public:
        PriorityQueue(int maxsize);
        ~PriorityQueue();
        void Inserir(int x, double peso);
        void Remover();
        pqNode* Topo();
        bool Vazio();

    private:
        int GetAncestral(int posicao);
        int GetSucessorEsq(int posicao);
        int GetSucessorDir(int posicao);
        int tamanho;
        pqNode* data;
};

#endif