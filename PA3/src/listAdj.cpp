#include "listAdj.hpp"

ListaAdjacencia::ListaAdjacencia() {
    this->lista = new ListaEncadeada[8];
    this->numVertices = 0;
    this->limite = 8;
}

ListaAdjacencia::~ListaAdjacencia() {
    delete[] this->lista;
}

void ListaAdjacencia::InsereVertice() {
    this->numVertices++;
    if (numVertices == limite) { this->Redimensionar(); }
}

void ListaAdjacencia::InsereAresta(int inicio, int destino) {
    this->lista[inicio].InsereFinal(destino);
}

int ListaAdjacencia::TamanhoTotal() {
    int total = 0;
    for (int i = 0; i<this->numVertices; i++) { total += this->lista[i].getTamanho(); }
    return total;
}

int ListaAdjacencia::MenorLista() {
    int menor = this->lista[0].getTamanho();
    for (int i = 1; i<this->numVertices; i++) {
        if (this->lista[i].getTamanho() < menor) { menor = this->lista[i].getTamanho(); }
    }

    return menor;
}

int ListaAdjacencia::MaiorLista() {
    int maior = this->lista[0].getTamanho();
    for (int i = 1; i<this->numVertices; i++) {
        if (this->lista[i].getTamanho() > maior) { maior = this->lista[i].getTamanho(); }
    }

    return maior;
}

void ListaAdjacencia::ImprimeIndividual(int x) {
    this->lista[x].Imprime();
}

void ListaAdjacencia::Redimensionar() {
    ListaEncadeada* nova = new ListaEncadeada[this->numVertices*2];
    for (int i = 0; i<this->numVertices; i++) {
        nova[i] = this->lista[i];
    }
    delete[] this->lista;

    this->lista = nova;
    this->limite = this->numVertices * 2;
}