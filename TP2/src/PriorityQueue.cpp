#include "PriorityQueue.hpp"

// Inicialização sem parâmetro. Apenas para inicializar o minHeap.
pqNode::pqNode() {
    this->peso = -1;
    this->vertice = -1;
}

// Construtor do nó com parâmetros.
pqNode::pqNode(int vertice, double peso, int portais) {
    this->vertice = vertice;
    this->peso = peso;
    this->portaisUsados = portais;
}

// Inicia o minHeap.
PriorityQueue::PriorityQueue(int maxsize) {
    this->tamanho = 0;
    this->data = new pqNode[maxsize];
    this->posicoesVertices = new int[maxsize];

    for (int i = 0; i<maxsize; i++) { posicoesVertices[i] = -1; }   // Indica que o vértice não foi adicionado no heap.
}

// Destrutor minHeap
PriorityQueue::~PriorityQueue() { delete[] this->data; delete[] this->posicoesVertices; }

// Insere um novo nó no heap
void PriorityQueue::Inserir(int vertice, double peso, int portais) {
    pqNode novo = pqNode(vertice, peso, portais);       // Cria o nó
    this->data[this->tamanho] = novo;                   // Insere o nó no fnal do vetor.
    this->posicoesVertices[vertice] = this->tamanho;    // Atualiza a posição do vértice no vetor de posições.

    // Faz o Heapify da propriedade caso a fila não esteja vazia.
    if (!this->Vazio()) { heapifyUp(this->tamanho); }

    this->tamanho++;    // Aumenta o tamanho do minHeap.
}

// Remove a raiz do heap
void PriorityQueue::Remover() {
    if (this->Vazio()) { return; }

    this->posicoesVertices[this->data[0].vertice] = -1;     // Atualiza o vetor de posições dos vértices.
    this->data[0] = this->data[this->tamanho-1];            // Substitui a raíz do minHeap pelo o que está na última posição.
    this->posicoesVertices[this->data[0].vertice] = 0;      // Atualiza posição no vetor.
    this->tamanho--;
    heapifyDown(0);                                         // Faz o heapify para baixo.
}

// Função de atualizar o peso do vértice, caso necessário.
void PriorityQueue::atualizarChave(int vertice, double peso, int portaisUsados) {
    int pos = this->posicoesVertices[vertice];
    this->data[pos].peso = peso;
    this->data[pos].portaisUsados = portaisUsados;
    heapifyUp(pos);
}

// Heapify para baixo.
void PriorityQueue::heapifyDown(int pos) {
    int sucEsq = this->GetSucessorEsq(pos);
    int sucDir = this->GetSucessorDir(pos);
    int menorSucessor;
    // É feita uma comparação para saber qual é o nó sucessor com menor valor. Este será usado para manter a propriedade do minHeap.
    if (this->data[sucEsq].peso <= this->data[sucDir].peso) { menorSucessor = sucEsq; }
    else { menorSucessor = sucDir; }

    // Enquanto o nó que foi colocado para substituir a raiz for maior que os seus sucessore, ele descerá na estrutura até achar sua posição.
    // Consequentemente, a primeira posição da estrutura será assumida pelo nó com menor valor de todo o minHeap.
    while (this->data[pos].peso > this->data[menorSucessor].peso) {
        int vMenorSuc = this->data[menorSucessor].vertice;
        int vFilho = this->data[pos].vertice;

        // Atualiza as posições do vértice no vetor de posições.
        this->posicoesVertices[vMenorSuc] = pos;
        this->posicoesVertices[vFilho] = menorSucessor;

        // Troca de posição entre os nós.
        pqNode aux = this->data[menorSucessor];
        this->data[menorSucessor] = this->data[pos];
        this->data[pos] = aux;

        // Atualização de variáveis para a próxima verificação do loop.
        pos = menorSucessor;
        sucEsq = this->GetSucessorEsq(pos);
        sucDir = this->GetSucessorDir(pos);
        if (this->data[sucEsq].peso <= this->data[sucDir].peso) { menorSucessor = sucEsq; }
        else { menorSucessor = sucDir; }
    }
}

// Heapify para cima.
void PriorityQueue::heapifyUp(int pos) {
    int pai = this->GetAncestral(pos);
    
    // Enquanto a estimativa do filho for menor que a de seu nó pai, o filho subirá na estrutura (assumirá posições menores no vetor).
    while (this->data[pos].peso < this->data[pai].peso) {
        int vPai = this->data[pai].vertice;
        int vFilho = this->data[pos].vertice;

        // Atualiza as posições do vértice no vetor de posições.
        this->posicoesVertices[vPai] = pos;
        this->posicoesVertices[vFilho] = pai;

        // Troca os nó pai com o filho.
        pqNode aux = this->data[pai];
        this->data[pai] = this->data[pos];
        this->data[pos] = aux;

        // Preparação para a proxima verificação. A posição do novo pai é obtida e o índice do novo nó é atualizada.
        pos = pai;
        pai = this->GetAncestral(pos);
    }
}

// Verifica se a estrutura está vazia.
bool PriorityQueue::Vazio() {
    if (this->tamanho == 0) { return true; }
    else { return false; }
}

// Retorna o nó da primeira posição do minHeap.
pqNode* PriorityQueue::Topo() {
    return &this->data[0];
}

// Retorna a posição do pai do nó que está em determinada posição.
int PriorityQueue::GetAncestral(int posicao) {
    return (posicao-1)/2;
}

// Retorna a posição do sucessor da esquerda do nó que está em determinada posição.
int PriorityQueue::GetSucessorEsq(int posicao) {
    int sucEsq = 2*posicao+1;
    if (sucEsq >= this->tamanho) { return posicao; }
    else { return sucEsq; }
}

// Retorna a posição do sucessor da direita do nó que está em determinada posição.
int PriorityQueue::GetSucessorDir(int posicao) {
    int sucDir = 2*posicao+2;
    if (sucDir >= this->tamanho) { return posicao; }
    else { return sucDir; }
}

void PriorityQueue::ImprimirTopo() {
    pqNode* no = this->Topo();
    std::cout << no->vertice << ' ' << no->peso << ' ' << no->portaisUsados << std::endl;
}