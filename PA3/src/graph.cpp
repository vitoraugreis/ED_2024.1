#include "graph.hpp"

Grafo::Grafo() {
    ListaAdjacencia vertices = ListaAdjacencia();
}

Grafo::~Grafo() {}

void Grafo::InsereVertice() { this->vertices.InsereVertice(); }

void Grafo::InsereAresta(int v, int w) { this->vertices.InsereAresta(v, w); }

int Grafo::QuantidadeVertices() { return this->vertices.numVertices; }

int Grafo::QuantidadeArestas() { return this->vertices.TamanhoTotal()/2; }

int Grafo::GrauMinimo() { return this->vertices.MenorLista(); }

int Grafo::GrauMaximo() { return this->vertices.MaiorLista(); }

void Grafo::ImprimeVizinhos(int v) { this->vertices.ImprimeIndividual(v); }