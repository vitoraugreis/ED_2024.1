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
    this->data = new AStarpqNode[maxsize];
}

AStarPriorityQueue::~AStarPriorityQueue() { delete[] this->data; }

// Insere um novo nó no minHeap.
void AStarPriorityQueue::Inserir(int vertice, double distPercorrida, double heuristica, int portais) {
    AStarpqNode novo = AStarpqNode(vertice, distPercorrida, heuristica, portais);   // Cria o nó.
    this->data[this->tamanho] = novo;   // Insere no final do vetor.

    // Caso a fila de prioridade esteja vazia, a verificação da estrutura não é necessária. Caso contrário sim (condição abaixo)
    if (!this->Vazio()) {
        int indice = this->tamanho;
        int pai = this->GetAncestral(indice);
        
        // Enquanto a estimativa do filho for menor que a de seu nó pai, o filho subirá na estrutura (assumirá posições menores no vetor).
        while (this->data[indice].estimativa < this->data[pai].estimativa) {
            // Troca os nó pai com o filho.
            AStarpqNode aux = this->data[pai];
            this->data[pai] = this->data[indice];
            this->data[indice] = aux;
            // Preparação para a proxima verificação. A posição do novo pai é obtida e o índice do novo nó é atualizada.
            indice = pai;
            pai = this->GetAncestral(indice);
        }
    }
    this->tamanho++;
}

void AStarPriorityQueue::Remover() {
    if (this->Vazio()) { return; }

    this->data[0] = this->data[this->tamanho-1];    // Substitui a raíz do minHeap pelo o que está na última posição.
    this->tamanho--;
    int indice = 0;

    int sucEsq = this->GetSucessorEsq(indice);
    int sucDir = this->GetSucessorDir(indice);
    int menorSucessor;
    // É feita uma comparação para saber qual é o nó sucessor com menor valor. Este será usado para manter a propriedade do minHeap.
    if (this->data[sucEsq].estimativa <= this->data[sucDir].estimativa) { menorSucessor = sucEsq; }
    else { menorSucessor = sucDir; }

    // Enquanto o nó que foi colocado para substituir a raiz for maior que os seus sucessore, ele descerá na estrutura até achar sua posição.
    // Consequentemente, a primeira posição da estrutura será assumida pelo nó com menor valor de todo o minHeap.
    while (this->data[indice].estimativa > this->data[menorSucessor].estimativa) {
        // Troca de posição entre os nós.
        AStarpqNode aux = this->data[menorSucessor];
        this->data[menorSucessor] = this->data[indice];
        this->data[indice] = aux;

        // Atualização de variáveis para a próxima verificação do loop.
        indice = menorSucessor;
        sucEsq = this->GetSucessorEsq(indice);
        sucDir = this->GetSucessorDir(indice);
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