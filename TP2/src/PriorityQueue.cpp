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
}

// Destrutor minHeap
PriorityQueue::~PriorityQueue() { delete[] this->data; }

void PriorityQueue::Inserir(int vertice, double peso, int portais) {
    pqNode novo = pqNode(vertice, peso, portais);   // Cria o nó
    this->data[this->tamanho] = novo;               // Insere o nó no fnal do vetor.

    // Faz a verificação da propriedade caso a fila não esteja vazia.
    if (!this->Vazio()) {
        int indice = this->tamanho;
        int pai = this->GetAncestral(indice);
        
        // Enquanto a estimativa do filho for menor que a de seu nó pai, o filho subirá na estrutura (assumirá posições menores no vetor).
        while (this->data[indice].peso < this->data[pai].peso) {
            // Troca os nó pai com o filho.
            pqNode aux = this->data[pai];
            this->data[pai] = this->data[indice];
            this->data[indice] = aux;
            // Preparação para a proxima verificação. A posição do novo pai é obtida e o índice do novo nó é atualizada.
            indice = pai;
            pai = this->GetAncestral(indice);
        }
    }

    this->tamanho++;    // Aumenta o tamanho do minHeap.
}

void PriorityQueue::Remover() {
    if (this->Vazio()) { return; }

    this->data[0] = this->data[this->tamanho-1]; // Substitui a raíz do minHeap pelo o que está na última posição.
    this->tamanho--;
    int indice = 0;

    int sucEsq = this->GetSucessorEsq(indice);
    int sucDir = this->GetSucessorDir(indice);
    int menorSucessor;
    // É feita uma comparação para saber qual é o nó sucessor com menor valor. Este será usado para manter a propriedade do minHeap.
    if (this->data[sucEsq].peso <= this->data[sucDir].peso) { menorSucessor = sucEsq; }
    else { menorSucessor = sucDir; }

    // Enquanto o nó que foi colocado para substituir a raiz for maior que os seus sucessore, ele descerá na estrutura até achar sua posição.
    // Consequentemente, a primeira posição da estrutura será assumida pelo nó com menor valor de todo o minHeap.
    while (this->data[indice].peso > this->data[menorSucessor].peso) {
        // Troca de posição entre os nós.
        pqNode aux = this->data[menorSucessor];
        this->data[menorSucessor] = this->data[indice];
        this->data[indice] = aux;

        // Atualização de variáveis para a próxima verificação do loop.
        indice = menorSucessor;
        sucEsq = this->GetSucessorEsq(indice);
        sucDir = this->GetSucessorDir(indice);
        if (this->data[sucEsq].peso <= this->data[sucDir].peso) { menorSucessor = sucEsq; }
        else { menorSucessor = sucDir; }
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