#include "AStarPriorityQueue.hpp"

// Inicialização sem parâmetro. Apenas para inicializar o minHeap.
AStarpqNode::AStarpqNode() {
    this->distPercorrida = -1;
    this->heuristica = -1;
    this->estimativa = -1;
    this->portaisUsados = -1;
    this->vertice = -1;
}

// Construtor do nó com parâmetros.
AStarpqNode::AStarpqNode(int vertice, double distPercorrida, double heuristica, int portais) {
    this->vertice = vertice;
    this->distPercorrida = distPercorrida;
    this->heuristica = heuristica;
    this->estimativa = distPercorrida + heuristica;
    this->portaisUsados = portais;
}

// Inicia o minHeap.
AStarPriorityQueue::AStarPriorityQueue(int maxsize) {
    this->tamanho = 0;
    this->data = new AStarpqNode[maxsize];      // Heap com tamanho informado.
    this->posicoesVertices = new int[maxsize];  // Inicia o vetor com o mesmo tamanho, para armazenar as posições.

    for (int i = 0; i<maxsize; i++) { posicoesVertices[i] = -1; }   // Indica que o vértice não foi adicionado no heap.
}

AStarPriorityQueue::~AStarPriorityQueue() { delete[] this->data; delete[] this->posicoesVertices; }

// Insere um novo nó no minHeap.
void AStarPriorityQueue::Inserir(int vertice, double distPercorrida, double heuristica, int portais) {
    AStarpqNode novo = AStarpqNode(vertice, distPercorrida, heuristica, portais);   // Cria o nó.
    this->data[this->tamanho] = novo;                   // Insere o nó no fnal do vetor.
    this->posicoesVertices[vertice] = this->tamanho;    // Atualiza a posição do vértice no vetor de posições.

     // Faz o Heapify da propriedade caso a fila não esteja vazia.
    if (!this->Vazio()) { heapifyUp(this->tamanho); }
    this->tamanho++;
}

// Remove a raiz do heap.
void AStarPriorityQueue::Remover() {
    if (this->Vazio()) { return; }

    this->posicoesVertices[this->data[0].vertice] = -1;     // Atualiza o vetor de posições dos vértices.
    this->data[0] = this->data[this->tamanho-1];            // Substitui a raíz do minHeap pelo o que está na última posição.
    this->posicoesVertices[this->data[0].vertice] = 0;      // Atualiza posição no vetor.
    this->tamanho--;
    this->heapifyDown(0);
}

// Função de atualizar o peso do vértice, caso necessário.
void AStarPriorityQueue::atualizarChave(int vertice, double distPercorrida, double heuristica, int portais) {
    int pos = this->posicoesVertices[vertice];          // Obrtem a posição no heap do vertice informado.

    // Atualiza as informações e faz o heapify com o nó atualizado. Para cima, pois o valor atualizado deve ser menor que o existente anteriormente.
    this->data[pos].distPercorrida = distPercorrida;    
    this->data[pos].heuristica = heuristica;
    this->data[pos].portaisUsados = portais;
    heapifyUp(pos);
}

// Heapify para cima.
void AStarPriorityQueue::heapifyUp(int pos) {
    int pai = this->GetAncestral(pos);
    
    // Enquanto a estimativa do filho for menor que a de seu nó pai, o filho subirá na estrutura (assumirá posições menores no vetor).
    while (this->data[pos].estimativa < this->data[pai].estimativa) {
        int vPai = this->data[pai].vertice;
        int vFilho = this->data[pos].vertice;

        // Atualiza as posições do vértice no vetor de posições.
        this->posicoesVertices[vPai] = pos;
        this->posicoesVertices[vFilho] = pai;

        // Troca os nó pai com o filho.
        AStarpqNode aux = this->data[pai];
        this->data[pai] = this->data[pos];
        this->data[pos] = aux;

        // Preparação para a proxima verificação. A posição do novo pai é obtida e o índice do novo nó é atualizada.
        pos = pai;
        pai = this->GetAncestral(pos);
    }
}

// Heapify para baixo.
void AStarPriorityQueue::heapifyDown(int pos) {
    int sucEsq = this->GetSucessorEsq(pos);
    int sucDir = this->GetSucessorDir(pos);
    int menorSucessor;
    // É feita uma comparação para saber qual é o nó sucessor com menor valor. Este será usado para manter a propriedade do minHeap.
    if (this->data[sucEsq].estimativa <= this->data[sucDir].estimativa) { menorSucessor = sucEsq; }
    else { menorSucessor = sucDir; }

    // Enquanto o nó que foi colocado para substituir a raiz for maior que os seus sucessore, ele descerá na estrutura até achar sua posição.
    // Consequentemente, a primeira posição da estrutura será assumida pelo nó com menor valor de todo o minHeap.
    while (this->data[pos].estimativa > this->data[menorSucessor].estimativa) {
        int vMenorSuc = this->data[menorSucessor].vertice;
        int vFilho = this->data[pos].vertice;

        // Atualiza as posições do vértice no vetor de posições.
        this->posicoesVertices[vMenorSuc] = pos;
        this->posicoesVertices[vFilho] = menorSucessor;

        // Troca de posição entre os nós.
        AStarpqNode aux = this->data[menorSucessor];
        this->data[menorSucessor] = this->data[pos];
        this->data[pos] = aux;

        // Atualização de variáveis para a próxima verificação do loop.
        pos = menorSucessor;
        sucEsq = this->GetSucessorEsq(pos);
        sucDir = this->GetSucessorDir(pos);
        if (this->data[sucEsq].estimativa <= this->data[sucDir].estimativa) { menorSucessor = sucEsq; }
        else { menorSucessor = sucDir; }
    }
}

// Verifica se a estrutura está vazia.
bool AStarPriorityQueue::Vazio() {
    if (this->tamanho == 0) { return true; }
    else { return false; }
}

// Retorna o nó da primeira posição do minHeap.
AStarpqNode* AStarPriorityQueue::Topo() {
    return &this->data[0];
}

// Retorna a posição do pai do nó que está em determinada posição.
int AStarPriorityQueue::GetAncestral(int posicao) {
    return (posicao-1)/2;
}

// Retorna a posição do sucessor da esquerda do nó que está em determinada posição.
int AStarPriorityQueue::GetSucessorEsq(int posicao) {
    int sucEsq = 2*posicao+1;
    if (sucEsq >= this->tamanho) { return posicao; }
    else { return sucEsq; }
}

// Retorna a posição do sucessor da direita do nó que está em determinada posição.
int AStarPriorityQueue::GetSucessorDir(int posicao) {
    int sucDir = 2*posicao+2;
    if (sucDir >= this->tamanho) { return posicao; }
    else { return sucDir; }
}

void AStarPriorityQueue::ImprimirTopo() {
    AStarpqNode* no = this->Topo();
    std::cout << no->vertice << ' ' << no->distPercorrida << ' ' << no->heuristica << ' ' << no->estimativa << ' ' << no->portaisUsados << std::endl;
}