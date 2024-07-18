#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include <iostream>

// Classe para armazenar as informações necessárias para o funcionamento do Dijkstra.
class pqNode {
    public:
        pqNode();               // Construtor sem parâmetros. Utilizado para inicar a fila de prioridade.
        pqNode(int vertice, double peso, int portais);  // Construtor com parâmetros.
        int vertice;            // Vértice atual.
        double peso;            // Distância percorrida até chegar ao vértice. Será usada para ordenar a fila de prioridade.
        int portaisUsados;      // Número de portais usados até a chegada neste vértice.
};

// Fila de prioridade usada no Dijkstra. Totalmente baseado na estrutra minHeap estudada em sala.
class PriorityQueue {
    public:
        PriorityQueue(int maxsize);
        ~PriorityQueue();
        void Inserir(int vertice, double peso, int portais);    // Insere um nó no heap e organiza a estrutura, se necessário.
        void Remover();                                         // Remove o primeiro nó do heap e organiza a estrutura.
        pqNode* Topo();                                         // Retorna o primeiro nó do heap.
        bool Vazio();                                           // Verifica se o heap está vazio.
        void ImprimirTopo();

    private:
        int GetAncestral(int posicao);
        int GetSucessorEsq(int posicao);
        int GetSucessorDir(int posicao);
        int tamanho;                        // Tamanho atual heap.
        pqNode* data;                       // Vetor de nós com as informações necessárias.
};

#endif