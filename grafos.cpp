#include "grafos.hpp"

void criaGrafo(int m, bool b, vector<Vertice>& grafo){
    Tdados dado;
    int o, d, p;
    for (int i = 0; i < m; i++) {
        cin >> o >> d >> p;
        dado.destino = d;
        dado.peso = p;
        grafo[o].visitado = false;
            
        if (grafo[o].arestas.empty()){
            grafo[o].arestas.emplace(grafo[o].arestas.begin(), dado);
        }else{
            grafo[o].arestas.emplace(grafo[o].arestas.end(), dado);
        }

        if(!b){
            dado.destino = o;
            if (grafo[d].arestas.empty()){
                grafo[d].arestas.emplace(grafo[d].arestas.begin(), dado);
            }else{
                grafo[d].arestas.emplace(grafo[d].arestas.end(), dado);
            }
        }
    }
}

void setMatrizdePesos(vector<Vertice> grafo, vector<vector<int>>& matrizdePesos){
    for (unsigned i = 0; i < matrizdePesos.size(); i++){
        matrizdePesos[i].resize(matrizdePesos.size());
        for (unsigned j = 0; j < matrizdePesos[i].size(); j++){
            for (auto it : grafo[i].arestas){
                if( (int) j == it.destino){
                    matrizdePesos[i][j] = it.peso;
                }
            }
        }
    }    
}

void vizualizaGrafo(int n, int m, bool b, vector<Vertice> grafo){
    cout << "\n" << n << " " << m << " ";
        
    if (!b) {
        cout << "NAO DIRECIONADO" << endl;
    }else{
        cout << "DIRECIONADO" << endl;
    }

    for (int i = 0; i < n+1; i++) {
        int o = i;
        for (auto it : grafo[i].arestas){
            cout << o << " " << it.destino << " " << it.peso << endl;
        }
    }
}

void vizualizaPesos(vector<vector<int>> matrizdePesos){
    cout << endl;
    for (unsigned i = 0; i < matrizdePesos.size(); i++){
        for (unsigned j = 0; j < matrizdePesos[i].size(); j++){
                cout << " " << matrizdePesos[i][j];
        }
        cout << endl;
    }
}

void DFS(list<int>& caminhos, vector<Vertice>& grafo, int indice){
    if(grafo[indice].visitado == false){
        grafo[indice].visitado = true;
        if (caminhos.empty()){
            caminhos.emplace(caminhos.begin(), indice);
        }else{
            caminhos.emplace(caminhos.end(), indice);
        }
    }
    for (auto it : grafo[indice].arestas){
        if (grafo[it.destino].visitado == false){
            DFS(caminhos, grafo, it.destino);
        }
    }
}

void BFS(vector<Vertice> grafo, int indice){
    list<int> caminhos;
    queue<int> Q;
    grafo[indice].visitado = true;
    caminhos.emplace(caminhos.begin(), indice);
    Q.push(indice);
    while (!Q.empty()){
        indice = Q.front();
        Q.pop();
        for (auto it : grafo[indice].arestas){
            if (grafo[it.destino].visitado == false){
                grafo[it.destino].visitado = true;
                Q.push(it.destino);
                caminhos.emplace(caminhos.end(), it.destino);
            }
        }
    }
    vizualizaCaminho(caminhos);
} 

void vizualizaCaminho(list<int> caminhos){
    for (auto it : caminhos){
        cout << it << " ";
    }
}

int distanciaMinima(vector<int> dist, vector<bool> Dset){
	int min=INT_MAX, indice;                
	for(unsigned v = 0; v < dist.size(); v++)
	{
		if(Dset[v]==false && dist[v]<=min)      
		{
			min=dist[v];
			indice=v;
		}
	}
	return indice;
}

void dijkstra(vector<vector<int>>& matrizdePesos, int fonte){
    vector<int> dist( matrizdePesos.size() );
    vector<bool> Dset( matrizdePesos.size() );
    vector<list<int>> caminhos(matrizdePesos.size());
    list<int>::iterator it;

    
    
    for (unsigned i=0;i<matrizdePesos.size();i++ ){
        dist[i] = INT_MAX;
        Dset[i] = false;
    }

    dist[fonte] = 0;

    for (unsigned c = 0; c < matrizdePesos.size(); c++){
        int u = distanciaMinima(dist, Dset);
        Dset[u] = true;
        for (unsigned v = 0; v < matrizdePesos.size(); v++){
            if (!Dset[v] && matrizdePesos[u][v] && dist[u] != INT_MAX && dist[u]+matrizdePesos[u][v] < dist[v]){
                dist[v] = dist[u]+matrizdePesos[u][v];
                it = find(caminhos[v].begin(), caminhos[v].end(), v);
                if(it != caminhos[v].end()){
                    caminhos[v].emplace(caminhos[v].begin(), u);    
                }else{
                    caminhos[v].emplace(caminhos[v].end(), v);
                }
            }
        }
    }

	for(unsigned i=fonte+1;i<matrizdePesos.size();i++){
        caminhos[i].emplace(caminhos[i].begin(), fonte);
		cout << i << "  (" << dist[i]<< ") :  ";
        vizualizaCaminho(caminhos[i]); 
        cout << endl;
	}

}


