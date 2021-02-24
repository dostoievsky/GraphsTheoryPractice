#ifndef grafos_hpp
#define grafos_hpp

    #include <iostream>
    #include <iterator> 
    #include <queue>
    #include<climits>
    #include <algorithm>   
    #include <vector>
    #include <list>

    using namespace std;

    typedef struct {
        int destino;
        int peso;
    }Tdados;

    typedef struct {
        list<Tdados> arestas;
        bool visitado;
    }Vertice;

    void criaGrafo(int m, bool b, vector<Vertice>& grafo);
    void setMatrizdePesos(vector<Vertice> grafo, vector<vector<int>>& matrizdePesos);
    void vizualizaPesos(vector<vector<int>> matrizdePesos);
    void vizualizaGrafo(int n, int m, bool b, vector<Vertice> grafo);
    void DFS(list<int>& caminhos, vector<Vertice>& grafo, int indice);
    void BFS(vector<Vertice>& grafo, int indice);
    void vizualizaCaminho(list<int> caminhos);
    int distanciaMinima(vector<int> dist, vector<bool> Dset);
    void dijkstra(vector<vector<int>>& matrizdePesos, int fonte);

#endif
