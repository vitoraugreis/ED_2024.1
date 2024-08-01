#include <iostream>
#include "minHeap.hpp"
#include "unionFind.hpp"

int main() {
    int valor = 0;
    int n, m; std::cin >> n >> m;

    UnionFind uf = UnionFind(n);
    MinHeap mh = MinHeap(m);

    for (int i = 0; i<n; i++) { uf.Make(i); }


    for (int i = 0; i<m; i++) {
        int u, c, v; std::cin >> u >> v >> c;
        mh.Inserir(u, v, c);
    }

    while (!mh.Vazio()) {
        Aresta aux = mh.Remover();
        if (uf.Find(aux.u) != uf.Find(aux.v)) {
            valor += aux.custo;
            uf.Union(aux.v, aux.u);
        }
    }

    std::cout << valor << std::endl;

    return 0;
}