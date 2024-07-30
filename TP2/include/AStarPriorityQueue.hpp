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
        void Inserir(int vertice, double distPercorrida, double heuristica, int portais);           // Insere um nó na fila.
        void Remover();                                                                             // Remove primeiro elemento da fila.
        void atualizarChave(int vertice, double distPercorrida, double heuristica, int portais);    // Atualiza um elemento presente na lista.
        AStarpqNode* Topo();                                                                        // Retorna o topo da lista.
        bool Vazio();
        void ImprimirTopo();

    private:
        int GetAncestral(int posicao);
        int GetSucessorEsq(int posicao);
        int GetSucessorDir(int posicao);
        void heapifyUp(int pos);                                // Função do heapify para cima.
        void heapifyDown(int pos);                              // Função do heapify para baixo.
        int tamanho;
        AStarpqNode* data;
        int* posicoesVertices;              // Guarda as posições dos vértices no heap para fácil acesso.

        friend class GrafoLA;
        friend class GrafoMA;
};

#endif