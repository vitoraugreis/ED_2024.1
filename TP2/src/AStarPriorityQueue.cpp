#include "AStarPriorityQueue.hpp"

AStarpqNode::AStarpqNode() {
    this->distPercorrida = -1;
    this->heuristica = -1;
    this->peso = -1;
    this->portaisUsados = -1;
    this->vertice = -1;
}

AStarpqNode::AStarpqNode(int vertice, double distPercorrida, double heuristica, int portais) {
    this->vertice = vertice;
    this->distPercorrida = distPercorrida;
    this->heuristica = heuristica;
    this->peso = distPercorrida + heuristica;
    this->portaisUsados = portais;
}

AStarPriorityQueue::AStarPriorityQueue(int maxsize) {
    this->tamanho = 0;
    this->data = new AStarpqNode[maxsize];
}

AStarPriorityQueue::~AStarPriorityQueue() { delete this->data; }

void AStarPriorityQueue::Inserir(int vertice, double distPercorrida, double heuristica, int portais) {
    AStarpqNode novo = AStarpqNode(vertice, distPercorrida, heuristica, portais);
    this->data[this->tamanho] = novo;
    if (!this->Vazio()) {
        int indice = this->tamanho;
        int pai = this->GetAncestral(indice);
        
        while (this->data[indice].peso < this->data[pai].peso) {
            AStarpqNode aux = this->data[pai];
            this->data[pai] = this->data[indice];
            this->data[indice] = aux;
            indice = pai;
            pai = this->GetAncestral(indice);
        }
    }

    this->tamanho++;
}

void AStarPriorityQueue::Remover() {
    if (this->Vazio()) { return; }

    this->data[0] = this->data[this->tamanho-1];
    this->tamanho--;
    int indice = 0;

    int sucEsq = this->GetSucessorEsq(indice);
    int sucDir = this->GetSucessorDir(indice);
    int menorSucessor;
    if (this->data[sucEsq].peso <= this->data[sucDir].peso) { menorSucessor = sucEsq; }
    else { menorSucessor = sucDir; }

    while (this->data[indice].peso > this->data[menorSucessor].peso) {
        AStarpqNode aux = this->data[menorSucessor];
        this->data[menorSucessor] = this->data[indice];
        this->data[indice] = aux;

        indice = menorSucessor;
        sucEsq = this->GetSucessorEsq(indice);
        sucDir = this->GetSucessorDir(indice);
        if (this->data[sucEsq].peso <= this->data[sucDir].peso) { menorSucessor = sucEsq; }
        else { menorSucessor = sucDir; }
    }
}

bool AStarPriorityQueue::Vazio() {
    if (this->tamanho == 0) { return true; }
    else { return false; }
}

AStarpqNode* AStarPriorityQueue::Topo() {
    return &this->data[0];
}

int AStarPriorityQueue::GetAncestral(int posicao) {
    return (posicao-1)/2;
}

int AStarPriorityQueue::GetSucessorEsq(int posicao) {
    int sucEsq = 2*posicao+1;
    if (sucEsq >= this->tamanho) { return posicao; }
    else { return sucEsq; }
}

int AStarPriorityQueue::GetSucessorDir(int posicao) {
    int sucDir = 2*posicao+2;
    if (sucDir >= this->tamanho) { return posicao; }
    else { return sucDir; }
}

void AStarPriorityQueue::ImprimirTopo() {
    AStarpqNode* no = this->Topo();
    std::cout << no->vertice << ' ' << no->distPercorrida << ' ' << no->heuristica << ' ' << no->peso << ' ' << no->portaisUsados << std::endl;
}