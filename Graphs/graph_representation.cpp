#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    vector<vector<int>> edges;

    public:

    Graph(int V){
        this->V = V;
    }

    void addEdge(int u, int v){
        edges.push_back({u,v});
    }

    void adj_list(){
        vector<vector<int>> adj(V);

        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=0; i<V; i++){
            cout<< i << " -> "; 
            for(auto j : adj[i]){
                cout<< j<< " ";
            }
            cout<<endl;
        }
    }

    void adj_mat(){
        vector<vector<int>> adj(V, vector<int>(V,0));

        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            adj[u][v] = 1;
            adj[v][u] = 1;
        }
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(i==j) adj[i][j] = 1;
            }
        }

        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g(7);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(4, 1);
    g.addEdge(4, 3);
    g.addEdge(1, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 2);

    cout<<"Adjacency list representation is: "<<endl;
    g.adj_list();

    cout<<"Adjacency matrix representation is: "<<endl;
    g.adj_mat(); 
    return 0;
}