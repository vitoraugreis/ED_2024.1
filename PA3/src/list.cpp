#include "list.hpp"

Celula::Celula() {
    this->valor = -1;
    this->prox = nullptr;
}

ListaEncadeada::ListaEncadeada() {
    this->primeiro = new Celula();
    this->ultimo = primeiro;
    this->tamanho = 0;
}

ListaEncadeada::~ListaEncadeada() {
    this->Limpa();
    delete this->primeiro;
}

int ListaEncadeada::getTamanho() {
    return this->tamanho;
}

void ListaEncadeada::InsereFinal(int valor) {
    Celula* nova = new Celula;
    nova->valor = valor;
    this->ultimo->prox = nova;
    this->ultimo = nova;
    this->tamanho++;
}

void ListaEncadeada::Imprime() {
    Celula* p;
    p = this->primeiro->prox;

    while (p != nullptr) {
        std::cout << p->valor << ' ';
        p = p->prox;
    }
    std::cout << std::endl;
}

void ListaEncadeada::Limpa() {
    Celula* p;
    p = this->primeiro->prox;

    while (p != nullptr) {
        this->primeiro->prox = p->prox;
        delete p;
        p = this->primeiro->prox;
    }
    this->ultimo = primeiro;
    this->tamanho = 0;
}