#include "GrafoLA.hpp"

// Construtor do Grafo representado por lista de adjacência.
GrafoLA::GrafoLA(int numVertices) {
    this->numVertices = numVertices;
    this->listaAdj = new Lista[numVertices];
}

// Adiciona aresta no grafo.
void GrafoLA::adicionarAresta(int origme, int destino, double peso) {
    listaAdj[origme].adicionarAresta(destino, peso);
}

// Mostra o grafo no console. (usado no ínicio para conferir a construção do grafo)
void GrafoLA::imprimirGrafo() {
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "Vértice " << i << ":";
        listaAdj[i].imprimirLista();
        std::cout << std::endl;
    }
}

// Algoritmo Dijkstra.
double GrafoLA::Dijkstra(int origem, int destino, int limitePortais) {
    int V = this->numVertices;
    double dist[V][limitePortais+1];        // Matriz com os vertices e a distância mínima percorrida de acordo com o número de portais usados.
    PriorityQueue pq = PriorityQueue(V);    // Fila de prioridade. Usada para escolher os caminhos com menor distância.

    for (int i = 0; i<V; i++) {
        for (int j = 0; j<=limitePortais; j++) {
            dist[i][j] = INF;               // Inicia todas as distâncias mínimas como "Infinito" para serem substituidas posteriormente com as ditâncias mínimas.
        }
    }

    dist[origem][0] = 0;
    pq.Inserir(origem, 0, 0);               // Insere o vértice de origem no minHeap com peso 0 e sem portais utilizados.

    while (!pq.Vazio()) {
        pqNode* node = pq.Topo();           // Recupera o topo da lista de prioridade (Menor valor de distância percorrida)
        int id = node->vertice;          
        double distancia = node->peso;
        int portais = node->portaisUsados;
        pq.Remover();                 

        if (id == destino) { return distancia; }            // Se o vértice retirado for o de destino, o algoritmo para.
        if (distancia > dist[id][portais]) { continue; }    // Se a distância encontrada para o vértice for maior que a encontrada anteriormente, ignore.

        dist[id][portais] = distancia;
        for (No* j = this->listaAdj[id].head; j != nullptr; j = j->prox) {  // Percorre a lista na posição do vértice encontrado para encontrar seus vizinhos.

            if (j->peso == 0 && portais >= limitePortais) { continue; }     // Ignora o vértice se ele for um portal e o limite de portais já for atingido.

            double w = distancia + j->peso;
            // Insere o vértie vizinho na fila de prioridade, com a distância percorrida atualizada.
            // Se a aresta é um portal, haverá um acrescimo no número de portais utilizados.
            if (j->peso == 0) {                             
                if (w < dist[j->destino][portais+1]) {
                    pq.Inserir(j->destino, w, portais+1);
                }
            } else if (w < dist[j->destino][portais]) {
                pq.Inserir(j->destino, w, portais);
            }
        }
    }
    return INF;
}

double GrafoLA::AStar(int origem, int destino, Vertice* vertices, int limitePortais) {
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

        visitados[id][portaisUsados] = true;        // Atualiza a posição da matriz.
        
        for (No* j = this->listaAdj[id].head; j != nullptr; j = j->prox) {  // Percorre a lista de adjacência para pegar todos os vizinhos do vértice atual.
            int idVizinho = j->destino;
            double pesoVizinho = j->peso;

            if (pesoVizinho == 0) { portaisUsados++; }          // Aumenta o número de portais caso o peso da aresta para o vizinho seja 0.
            if (portaisUsados > limitePortais) { continue; }    // Ignora o vértice caso passe o limite de portais que podem ser utilizados.
            if (visitados[idVizinho][portaisUsados]) { continue; }  // Ignora o vértice vizinho se ele já tiver sido visitado.

            double distPercorridaAtual = distancia + pesoVizinho;
            double heuristica = vertices[idVizinho].CalcularDistancia(&vertices[destino]);
            pq.Inserir(idVizinho, distPercorridaAtual, heuristica, portaisUsados);
        }
    }
    return INF;          // Retorna INF caso não encontrar o caminho.
}