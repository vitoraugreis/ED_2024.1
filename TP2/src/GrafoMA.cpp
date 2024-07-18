#include "GrafoMA.hpp"

GrafoMA::GrafoMA(int numVertices) {
    this->numVertices = numVertices;
    this->matrizAdj = new double*[numVertices];

    for (int i = 0; i<numVertices; i++) {
        this->matrizAdj[i] = new double[numVertices];
        for (int j = 0; j<numVertices; j++) {
           this->matrizAdj[i][j] = INF;
        }
    }
}

GrafoMA::~GrafoMA() {
    for (int i = 0; i<numVertices; i++) {
        delete[] this->matrizAdj[i];
    }
    delete[] this->matrizAdj;
}

void GrafoMA::adicionarAresta(int origem, int destino, double peso) {
    this->matrizAdj[origem][destino] = peso;
}

void GrafoMA::imprimirGrafo() {
    for (int i = 0; i<numVertices; i++) {
        for (int j = 0; j<numVertices; j++) {
            std::cout << this->matrizAdj[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}

double GrafoMA::Dijkstra(int origem, int destino, int limitePortais) {
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
        for (int j = 0; j<V; j++) {
            double pesoVizinho = this->matrizAdj[id][j];
            if (pesoVizinho == INF) { continue; }
            double w = distancia + pesoVizinho;
            if ( pesoVizinho == 0 && portais < limitePortais) {          // Se a aresta tem peso 0 e o número de portais usados é menor doque o limite permitido.
                if (w < dist[j][portais+1]) {
                    pq.Inserir(j, w, portais+1);
                }
            } else if (w < dist[j][portais]) {
                pq.Inserir(j, w, portais);
            }
        }
    }

    double min = INF;
    for (int i = 0; i<=limitePortais; i++) {
        if (dist[destino][i] < min) { min = dist[destino][i]; }
    }
    return min;
}

double GrafoMA::AStar(int origem, int destino, Vertice* vertices, int limitePortais) {
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
        
        for (int j = 0; j<V; j++) {
            double pesoVizinho = this->matrizAdj[id][j];

            if (pesoVizinho == INF) { continue; }
            if (pesoVizinho == 0) { portaisUsados++; }
            if (portaisUsados > limitePortais) { continue; }
            if (vizitados[j][portaisUsados]) { continue; }

            double distPercorridaAtual = distancia + pesoVizinho;
            double heuristica = vertices[j].CalcularDistancia(&vertices[destino]);
            pq.Inserir(j, distPercorridaAtual, heuristica, portaisUsados);
        }
    }
    return INF;          // Retorna INF caso não encontrar o caminho.
}