#include "listAdj.hpp"

ListaAdjacencia::ListaAdjacencia() {
    this->primeiro = new ListaEncadeada;
    this->ultimo = this->primeiro;
    this->numVertices = 0;
}

ListaAdjacencia::~ListaAdjacencia() {
    this->Limpa();
    delete this->primeiro;
}

void ListaAdjacencia::InsereVertice() {
    ListaEncadeada* aux = new ListaEncadeada;
    aux->id = this->numVertices;
    this->ultimo->prox = aux;
    this->ultimo = this->ultimo->prox;
    this->numVertices++;
}

void ListaAdjacencia::InsereAresta(int inicio, int destino) {
    ListaEncadeada* aux = this->primeiro->prox;
    while (aux->id != inicio) {
        aux = aux->prox;
        if (aux == nullptr) { return; }
    }
    aux->InsereFinal(destino);
}

int ListaAdjacencia::TamanhoTotal() {
    int total = 0;
    ListaEncadeada* aux = this->primeiro->prox;
    while (aux != nullptr) {
        total += aux->getTamanho();
        aux = aux->prox;
    }

    return total;
}

int ListaAdjacencia::MenorLista() {
    ListaEncadeada* aux = this->primeiro->prox;
    int menor = aux->tamanho;
    aux = aux->prox;

    while (aux != nullptr) {
        if (aux->tamanho < menor) { menor = aux->tamanho; }
        aux = aux->prox;
    }

    return menor;
}

int ListaAdjacencia::MaiorLista() {
    ListaEncadeada* aux = this->primeiro->prox;
    int maior = aux->tamanho;
    aux = aux->prox;

    while (aux != nullptr) {
        if (aux->tamanho > maior) { maior = aux->tamanho; }
        aux = aux->prox;
    }

    return maior;
}

ListaEncadeada* ListaAdjacencia::Procurar(int x) {
    ListaEncadeada* aux = this->primeiro->prox;
    while (aux->id != x) {
        aux = aux->prox;
        if (aux == nullptr) { return nullptr; }
    }
    return aux;
}

void ListaAdjacencia::Imprime() {
    ListaEncadeada* aux = this->primeiro->prox;
    while (aux != nullptr) {
        aux->Imprime();
        aux = aux->prox;
    }
}

void ListaAdjacencia::Limpa() {
    ListaEncadeada* aux;
    aux = this->primeiro->prox;

    while (aux != nullptr) {
        this->primeiro->prox = aux->prox;
        delete aux;
        aux = this->primeiro->prox;
    }
    this->ultimo = primeiro;
    this->numVertices = 0;
}