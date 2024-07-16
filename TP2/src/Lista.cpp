#include "Lista.hpp"

Lista::Lista() {
    this->primeiro = new Celula();
    this->ultimo = primeiro;
}

Lista::~Lista() {
    this->Limpa();
    delete this->primeiro;
}

void Lista::Limpa() {
    Celula* p;
    p = this->primeiro->prox;
    while (p != nullptr) {
        this->primeiro->prox = p->prox;
        delete p;
        p = primeiro->prox;
    }
    this->ultimo = this->primeiro;
}

bool Lista::Vazia() {
    if (this->primeiro == this->ultimo) { return true; }
    return false;
}

void Lista::Insere(int id,  double peso) {
    Celula* nova;
    nova = new Celula();
    nova->item.idVertice = id;
    nova->item.peso = peso;
    this->ultimo->prox = nova;
    this->ultimo = nova;
}

bool Lista::Pesquisa(int idVertice) {
    Celula* aux = this->primeiro;
    while (aux != nullptr) {
        if (aux->item.idVertice == idVertice) {
            return true;
        }
        aux = aux->prox;
    }
    return false;
}

void Lista::Imprime() {
    Celula* p = this->primeiro->prox;
    while (p != nullptr) {
        std::cout << p->item.idVertice << ' ' << p->item.peso << std::endl;
        p = p->prox;
    }
}

Celula::Celula() {
    this->item = Item();
    this->prox = nullptr;
}

Item::Item() {
    this->idVertice = -1;
    this->peso = -1;
}