#include "GrafoMA.hpp"

// Construtor do Grafo representado por lista de adjacência.
GrafoMA::GrafoMA(int numVertices) {
    this->numVertices = numVertices;
    this->matrizAdj = new double*[numVertices];

    for (int i = 0; i<numVertices; i++) {
        this->matrizAdj[i] = new double[numVertices];
        for (int j = 0; j<numVertices; j++) {
            // Inicia todas as posições da matriz com INF para informar que não existe aresta entre eles.
            // Não foi inicada com 0 para não causar confusões com os portais.
            this->matrizAdj[i][j] = INF;
        }
    }
}

// Destrutor do grafo.
GrafoMA::~GrafoMA() {
    for (int i = 0; i<numVertices; i++) {
        delete[] this->matrizAdj[i];
    }
    delete[] this->matrizAdj;
}

// Adiciona Aresta no grafo.
void GrafoMA::adicionarAresta(int origem, int destino, double peso) {
    this->matrizAdj[origem][destino] = peso;
}

// Mostra o grafo.
void GrafoMA::imprimirGrafo() {
    for (int i = 0; i<numVertices; i++) {
        for (int j = 0; j<numVertices; j++) {
            std::cout << this->matrizAdj[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}

// Algoritmo de Dijkstra
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

        if (id == destino) { return distancia; }            // Se o vértice retirado for o de destino, o algoritmo para.

        for (int j = 0; j<V; j++) {
            double pesoVizinho = this->matrizAdj[id][j];

            if (pesoVizinho == INF) { continue; }   // Se o vizinho tiver valor na matriz de adjacência INF, ignorar (não é vizinho).
            if (pesoVizinho == 0 && portais >= limitePortais) { continue; }     // Caso o número máximo de portais tiver sido atingido, ignorar este portal.

            double w = distancia + pesoVizinho;
            int novoPortal = (pesoVizinho == 0) ? portais+1 : portais;

            if (dist[j][novoPortal] > w) {
                dist[j][novoPortal] = w;
                if (pq.posicoesVertices[j] == -1) {
                    pq.Inserir(j, w, novoPortal);
                } else {
                    pq.atualizarChave(j, w, novoPortal);
                }
            }
        }
    }

    return INF;     // Retorna INF caso o caminho não tenha sido encontrado.
}

// Algoritmo A*.
double GrafoMA::AStar(int origem, int destino, Vertice* vertices, int limitePortais) {
    int V = this->numVertices;
    bool visitados[V][limitePortais+1]; // Matriz que representa o vértice e o número de portais usados até chegar a ele.

    for (int i = 0; i<V; i++) {
        for (int j = 0; j<= limitePortais; j++) { 
            // Inicia todas as posições da matriz como false.
            // Caso o vértice i seja alcançado usando j portais, a posição [i][j] é trocada para true.
            visitados[i][j] = false; 
        }
    }

    AStarPriorityQueue pq = AStarPriorityQueue(V);
    // A heuristica utilizada é a distância euclidiana do vértice atual até o vértice de destino.
    // A classe Vertice possui um método para fazer tal calculo.
    double heuristicaInicial = vertices[origem].CalcularDistancia(&vertices[destino]);
    pq.Inserir(origem, 0, heuristicaInicial, 0);

    while (!pq.Vazio()) {
        AStarpqNode* node = pq.Topo();
        int id = node->vertice;
        int portaisUsados = node->portaisUsados;
        double distancia = node->distPercorrida;
        pq.Remover();

        if (id == destino) { return distancia; }    // Acaba o algoritmo se o vértice de destino for retirado do minHeap.
        
        for (int j = 0; j<V; j++) {                 // Percorre a matriz de adjacência para pegar todos os vizinhos do vértice atual.
            double pesoVizinho = this->matrizAdj[id][j];
            if (pesoVizinho == INF) { continue; }               // Se o valor na matriz for INF significa que não é vizinho.

            int novoPortal = (pesoVizinho == 0) ? portaisUsados+1 : portaisUsados;
            if (novoPortal >= limitePortais) { continue; } // Ignora o vértice caso passe o limite de portais que podem ser utilizados.

            if (!visitados[j][novoPortal]) {
                visitados[j][novoPortal] = true;
                double distPercorridaAtual = distancia + pesoVizinho;
                double heuristica = vertices[j].CalcularDistancia(&vertices[destino]);

                if (pq.posicoesVertices[j] == -1) {
                    pq.Inserir(j, distPercorridaAtual, heuristica, portaisUsados);
                } else {
                    pq.atualizarChave(j, distPercorridaAtual, heuristica, portaisUsados);
                }
            }
        }
    }
    return INF;          // Retorna INF caso não encontrar o caminho.
}