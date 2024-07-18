#include "PriorityQueue.hpp"

pqNode::pqNode() {
    this->peso = -1;
    this->vertice = -1;
}

pqNode::pqNode(int vertice, double peso, int portais) {
    this->vertice = vertice;
    this->peso = peso;
    this->portaisUsados = portais;
}

PriorityQueue::PriorityQueue(int maxsize) {
    this->tamanho = 0;
    this->data = new pqNode[maxsize];
}

PriorityQueue::~PriorityQueue() { delete this->data; }

void PriorityQueue::Inserir(int vertice, double peso, int portais) {
    pqNode novo = pqNode(vertice, peso, portais);
    this->data[this->tamanho] = novo;
    if (!this->Vazio()) {
        int indice = this->tamanho;
        int pai = this->GetAncestral(indice);
        
        while (this->data[indice].peso < this->data[pai].peso) {
            pqNode aux = this->data[pai];
            this->data[pai] = this->data[indice];
            this->data[indice] = aux;
            indice = pai;
            pai = this->GetAncestral(indice);
        }
    }

    this->tamanho++;
}

void PriorityQueue::Remover() {
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
        pqNode aux = this->data[menorSucessor];
        this->data[menorSucessor] = this->data[indice];
        this->data[indice] = aux;

        indice = menorSucessor;
        sucEsq = this->GetSucessorEsq(indice);
        sucDir = this->GetSucessorDir(indice);
        if (this->data[sucEsq].peso <= this->data[sucDir].peso) { menorSucessor = sucEsq; }
        else { menorSucessor = sucDir; }
    }
}

bool PriorityQueue::Vazio() {
    if (this->tamanho == 0) { return true; }
    else { return false; }
}

pqNode* PriorityQueue::Topo() {
    return &this->data[0];
}

int PriorityQueue::GetAncestral(int posicao) {
    return (posicao-1)/2;
}

int PriorityQueue::GetSucessorEsq(int posicao) {
    int sucEsq = 2*posicao+1;
    if (sucEsq >= this->tamanho) { return posicao; }
    else { return sucEsq; }
}

int PriorityQueue::GetSucessorDir(int posicao) {
    int sucDir = 2*posicao+2;
    if (sucDir >= this->tamanho) { return posicao; }
    else { return sucDir; }
}

void PriorityQueue::ImprimirTopo() {
    pqNode* no = this->Topo();
    std::cout << no->vertice << ' ' << no->peso << ' ' << no->portaisUsados << std::endl;
}