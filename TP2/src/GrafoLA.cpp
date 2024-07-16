#include "GrafoLA.hpp"

Grafo::Grafo(int numVertices, int numArestas) {
    this->numVertices = numVertices;
    this->numArestas = numArestas;
    this->listaAdj = new Vertice[numVertices];

    for (int i = 0; i<numVertices; i++) { this->listaAdj[i].SetId(i); }
}

Grafo::~Grafo() {
   for (int i = 0; i<this->numVertices; i++) {
        delete this->listaAdj[i].vizinhos;
    }
    delete this->listaAdj;
}

void Grafo::AtualizaVertice(int id, int x, int y) {
    this->listaAdj[id].SetCoords(x, y);
}

void Grafo::InsereAresta(int v1, int v2) {
    double peso = this->CalcularPeso(this->listaAdj[v1].x, this->listaAdj[v2].x, this->listaAdj[v1].y, this->listaAdj[v2].y);
    Lista* l = this->listaAdj[v1].vizinhos;
    l->Insere(v2, peso);
}

void Grafo::InsereArestaSemPeso(int v1, int v2) {
    Lista* l = this->listaAdj[v1].vizinhos;
    l->Insere(v2, 0);
}

bool Grafo::ExisteAresta(int v1, int v2) {
    Lista* l = this->listaAdj[v1].vizinhos;
    return l->Pesquisa(v2);
}

bool Grafo::ListaAdjVazia() {
    for (int i = 0; i<numVertices; i++) {
        Lista* l = this->listaAdj[i].vizinhos;
        if (! l->Vazia()) {
            return false;
        }
    }
    return true;
}

void Grafo::ImprimeGrafo() {
    if (this->ListaAdjVazia()) { std::cout << "Grafo vazio."; return; }

    for (int i = 0; i<numVertices; i++) {
        std::cout << i << std::endl;
        Lista* l = this->listaAdj[i].vizinhos;
        if (l->Vazia()) {  std::cout << "Sem arestas partindo do vertice." << std::endl; }
        else { l->Imprime(); }
        std::cout << "============================" << std::endl;
    }
}

double Grafo::CalcularPeso(int x1, int x2, int y1, int y2) {
    int Dx = x1-x2; Dx *= Dx;
    int Dy = y1-y2; Dy *= Dy;

    return sqrt((Dx + Dy));
}

Vertice::Vertice() {
    this->id = -1;
    this->x = -1;
    this->y = -1;
    this->vizinhos = new Lista();
}

void Vertice::SetId(int id) {
    this->id = id;
}

void Vertice::SetCoords(int x, int y) {
    this->x = x;
    this->y = y;
}

/*double Grafo::Dijkstra() {
    int antecessor[this->numVertices];
    double peso[this->numVertices];
    bool itensHeap[this->numVertices];
    int Pos[this->numVertices];
    int u, v;

    for (u = 0; u<this->numVertices; u++) {
        antecessor[u] = -1;
        peso[u] = INF;
    }
}*/