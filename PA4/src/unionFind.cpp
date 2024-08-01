#include "unionFind.hpp"

UnionFind::UnionFind(int quantidade_subconjuntos) {
    this->subconjuntos = new Subconjunto[quantidade_subconjuntos];
    this->tamanho = quantidade_subconjuntos;
}

UnionFind::~UnionFind() { delete[] this->subconjuntos; }

void UnionFind::Make(int x) {
    subconjuntos[x].representante = x;
    subconjuntos[x].rank = 0;
}

int UnionFind::Find(int x) {
    while (subconjuntos[x].representante != x) {
        x = subconjuntos[x].representante;
    }
    return x;
}

void UnionFind::Union(int x, int y) {
    int raiz_x = this->Find(x);
    int raiz_y = this->Find(y);

    if (raiz_x < raiz_y) {
        this->subconjuntos[raiz_x].representante = raiz_y;
    } else if (raiz_x > raiz_y) {
        this->subconjuntos[raiz_y].representante = raiz_x;
    } else {
        this->subconjuntos[raiz_y].representante = raiz_x;
        this->subconjuntos[raiz_x].rank++;
    }
}