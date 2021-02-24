#include "grafos.hpp"

int main (void) {
    int n, m, indice;
    bool b;
    cin >> n >> m >> b >> indice;
    if ( (n < 1) || (m < 0) || (indice < 1) || (indice > n+1)){
        return 0;    
    }else{
        vector<Vertice> grafo(n+1);
        vector<vector<int>> matrizdePesos(n+1);
        criaGrafo(m, b, grafo);
        setMatrizdePesos(grafo, matrizdePesos);
        dijkstra(matrizdePesos, indice);
        grafo.clear();
        matrizdePesos.clear();   
    }  
    return 0;
}