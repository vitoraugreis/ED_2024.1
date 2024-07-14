#include "heap.hpp"
#include <iostream>

using namespace std;

int main() {
    int tamanho, numero;
    cin >> tamanho;

    Heap minHeap(tamanho);

    int i;
    for (i = 0; i<tamanho; i++) {
        cin >> numero;
        minHeap.Inserir(numero);
    }

    for (i = 0; i<tamanho; i++) {
        cout << minHeap.Remover() << ' ';
    }
    cout << endl;
    
    return 0;
}