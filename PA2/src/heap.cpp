#include "heap.hpp"

Heap::Heap(int maxsize) {
    this->data = new int[maxsize];
    this->tamanho = 0;
}

Heap::~Heap() {
    delete this->data;
}

void Heap::Inserir(int x) {
    this->data[this->tamanho] = x;
    if (!this->Vazio()) {
        int indice = this->tamanho;
        int pai = this->GetAncestral(indice);
        
        while (this->data[indice] < this->data[pai]) {
            int aux = this->data[pai];
            this->data[pai] = this->data[indice];
            this->data[indice] = aux;
            indice = pai;
            pai = this->GetAncestral(indice);
        }
    }
    
    this->tamanho++;
}

int Heap::Remover() {
    if (this->Vazio()) { return -1; }

    int raiz = this->data[0];
    this->data[0] = this->data[this->tamanho-1];
    this->tamanho--;
    int indice = 0;

    int sucEsq = this->GetSucessorEsq(indice);
    int sucDir = this->GetSucessorDir(indice);
    int menorSucessor;
    if (this->data[sucEsq] <= this->data[sucDir]) { menorSucessor = sucEsq; }
    else { menorSucessor = sucDir; }

    while (this->data[indice] > this->data[menorSucessor]) {
        int aux = this->data[menorSucessor];
        this->data[menorSucessor] = this->data[indice];
        this->data[indice] = aux;

        indice = menorSucessor;
        sucEsq = this->GetSucessorEsq(indice);
        sucDir = this->GetSucessorDir(indice);
        if (this->data[sucEsq] <= this->data[sucDir]) { menorSucessor = sucEsq; }
        else { menorSucessor = sucDir; }
    }

    return raiz;
}

bool Heap::Vazio() {
    if (this->tamanho == 0) { return true; }
    else { return false; }
}

int Heap::GetAncestral(int posicao) {
    return (posicao-1)/2;
}

int Heap::GetSucessorEsq(int posicao) {
    int sucEsq = 2*posicao+1;
    if (sucEsq >= this->tamanho) { return posicao; }
    else { return sucEsq; }
}

int Heap::GetSucessorDir(int posicao) {
    int sucDir = 2*posicao+2;
    if (sucDir >= this->tamanho) { return posicao; }
    else { return sucDir; }
}