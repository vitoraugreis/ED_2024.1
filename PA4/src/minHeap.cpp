#include "minHeap.hpp"

MinHeap::MinHeap(int tamanho){
    this->data = new Aresta[tamanho];
    this->tamanho = 0;
}

MinHeap::~MinHeap(){ delete[] this->data; }

void MinHeap::Inserir(int u, int v, int peso){
    Aresta nova = Aresta();
    nova.u = u; nova.v = v; nova.custo = peso;

    this->data[this->tamanho] = nova;

    if (!this->Vazio()) { heapifyUp(this->tamanho); }

    this->tamanho++;
}

Aresta MinHeap::Remover(){
    if (this->Vazio()) { return Aresta(); }

    Aresta x = this->data[0];
    this->data[0] = this->data[this->tamanho-1];
    this->tamanho--;
    heapifyDown(0);

    return x;
}

bool MinHeap::Vazio(){
    if (this->tamanho == 0) { return true; }
    else { return false; }
}

int MinHeap::GetAncestral(int posicao){ return (posicao-1)/2; }

int MinHeap::GetSucessorEsq(int posicao){
    int sucEsq = 2*posicao+1;
    if (sucEsq >= this->tamanho) { return posicao; }
    else { return sucEsq; }
}

int MinHeap::GetSucessorDir(int posicao){
    int sucDir = 2*posicao+2;
    if (sucDir >= this->tamanho) { return posicao; }
    else { return sucDir; }
}

void MinHeap::heapifyUp(int pos){
    int pai = this->GetAncestral(pos);

    while (this->data[pos].custo < this->data[pai].custo) {
        Aresta aux = this->data[pai];
        this->data[pai] = this->data[pos];
        this->data[pos] = aux;

        pos = pai;
        pai = this->GetAncestral(pos);
    }
}

void MinHeap::heapifyDown(int pos){
    int sucEsq = this->GetSucessorEsq(pos);
    int sucDir = this->GetSucessorDir(pos);
    int menorSucessor;
    if (this->data[sucEsq].custo <= this->data[sucDir].custo) { menorSucessor = sucEsq; }
    else { menorSucessor = sucDir; }

    while (this->data[pos].custo > this->data[menorSucessor].custo) {
        Aresta aux = this->data[menorSucessor];
        this->data[menorSucessor] = this->data[pos];
        this->data[pos] = aux;

        pos = menorSucessor;
        sucEsq = this->GetSucessorEsq(pos);
        sucDir = this->GetSucessorDir(pos);
        if (this->data[sucEsq].custo <= this->data[sucDir].custo) { menorSucessor = sucEsq; }
        else { menorSucessor = sucDir; }
    }
}
void MinHeap::ImprimirTopo() {
    Aresta aux = this->data[0];
    std::cout << "Topo: " << aux.u << ' ' << aux.v << ' ' << aux.custo << std::endl;
}