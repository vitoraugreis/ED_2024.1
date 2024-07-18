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

double GrafoLA::Dijkstra(int origem, int destino, int limitePortais) {
    int V = this->numVertices;
    double dist[V][limitePortais+1];        // Matriz com os vertices e a distância mínima percorrida de acordo com o número de portais usados.
    PriorityQueue pq = PriorityQueue(V);

    for (int i = 0; i<V; i++) {
        for (int j = 0; j<=limitePortais; j++) {
            dist[i][j] = INF;               // Inicia todas as distâncias mínimas como "Infinito".
        }
    }

    dist[origem][0] = 0;
    pq.Inserir(origem, 0, 0);

    while (!pq.Vazio()) {
        pqNode* node = pq.Topo();           // Recupera o topo da lista de prioridade (Menor valor de peso)
        int id = node->vertice;          
        double distancia = node->peso;
        int portais = node->portaisUsados;
        pq.Remover();                       // Remove o nó da lista de prioridade.

        if (distancia > dist[id][portais]) { continue; }

        dist[id][portais] = distancia;
        for (No* j = this->listaAdj[id].head; j != nullptr; j = j->prox) {
            
            if (j->peso == 0 && portais >= limitePortais) { continue; }

            double w = distancia + j->peso;
            if (j->peso == 0) {                         // Se a aresta tem peso 0 e o número de portais usados é menor doque o limite permitido.
                if (w < dist[j->destino][portais+1]) {
                    pq.Inserir(j->destino, w, portais+1);
                }
            } else if (w < dist[j->destino][portais]) {
                pq.Inserir(j->destino, w, portais);
            }
        }
    }

    double min = INF;
    for (int i = 0; i<=limitePortais; i++) {
        if (dist[destino][i] < min) { min = dist[destino][i]; }
    }
    return min;
}

double GrafoLA::AStar(int origem, int destino, Vertice* vertices, int limitePortais) {
    int V = this->numVertices;
    bool vizitados[V][limitePortais+1];

    for (int i = 0; i<V; i++) {
        for (int j = 0; j<= limitePortais; j++) { 
            vizitados[i][j] = false; 
        }
    }

    AStarPriorityQueue pq = AStarPriorityQueue(V);
    double heuristicaInicial = vertices[origem].CalcularDistancia(&vertices[destino]);
    pq.Inserir(origem, 0, heuristicaInicial, 0);

    while (!pq.Vazio()) {
        AStarpqNode* node = pq.Topo();
        int id = node->vertice;
        int portaisUsados = node->portaisUsados;
        double distancia = node->distPercorrida;
        pq.Remover();

        if (id == destino) { return distancia; }

        vizitados[id][portaisUsados] = true;
        
        for (No* j = this->listaAdj[id].head; j != nullptr; j = j->prox) {
            int idVizinho = j->destino;
            double pesoVizinho = j->peso;

            if (pesoVizinho == 0) { portaisUsados++; }
            if (portaisUsados > limitePortais) { continue; }
            if (vizitados[idVizinho][portaisUsados]) { continue; }

            double distPercorridaAtual = distancia + pesoVizinho;
            double heuristica = vertices[idVizinho].CalcularDistancia(&vertices[destino]);
            pq.Inserir(idVizinho, distPercorridaAtual, heuristica, portaisUsados);
        }
    }
    return INF;          // Retorna INF caso não encontrar o caminho.
}