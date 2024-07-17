#include "Lista.hpp"

No::No(int destino, double peso) {
    this->destino = destino;
    this->peso = peso;
    this->prox = nullptr;
}

Lista::Lista() {
    this->head = nullptr;
}

void Lista::adicionarAresta(int destino, double peso) {
    No* aresta = new No(destino, peso);
    aresta->prox = this->head;
    head = aresta;
}

void Lista::imprimirLista() {
    No* atual = head;
    while (atual) {
        std::cout << " -> " << atual->destino << " (peso " << atual->peso << ")";
        atual = atual->prox;
    }
}