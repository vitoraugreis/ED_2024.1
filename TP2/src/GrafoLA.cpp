#include "GrafoLA.hpp"

GrafoLA::GrafoLA(int numVertices) {
    this->numVertices = numVertices;
    this->listaAdj = new Lista[numVertices];
}

void GrafoLA::adicionarAresta(int origme, int destino, double peso) {
    listaAdj[origme].adicionarAresta(destino, peso);
}

void GrafoLA::imprimirGrafo() {
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "Vértice " << i << ":";
        listaAdj[i].imprimirLista();
        std::cout << std::endl;
    }
}

double GrafoLA::Dijkstra(int origem, int destino) {
    int V = this->numVertices; 
    double dist[V];
    PriorityQueue pq = PriorityQueue(V);

    for (int i = 0; i<V; i++) {
        dist[i] = INF;
    }

    dist[origem] = 0;
    pq.Inserir(origem, 0);

    while (!pq.Vazio()) {
        pqNode* p = pq.Topo();
        int u = p->vertice;
        double d = p->peso;
        pq.Remover();

        if (d > dist[u]) { continue; }
        
        dist[u] = d;
        for (No* j = this->listaAdj[u].head; j != nullptr; j = j->prox) {
            double w = d + j->peso;
            if (dist[j->destino] > w) {
                pq.Inserir(j->destino, w);
            }
        }
    }
    return dist[destino];
}
    