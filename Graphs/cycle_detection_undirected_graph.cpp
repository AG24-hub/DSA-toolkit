#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V, E;
    vector<vector<int>> edges;
    vector<vector<int>> adj;

    public:

    Graph(int V, int E){
        this->V = V;
        this->E = E;
        adj.resize(V+1);
    }

    void addEdge(int u, int v){
        edges.push_back({u,v});
    }

    void adj_list(){

        for(int i=0; i<E; i++){
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=1; i<=V; i++){
            cout<< i << " -> "; 
            for(auto j : adj[i]){
                cout<< j<< " ";
            }
            cout<<endl;
        }
    }

    bool cycle_bfs(){
        vector<int> seen(V+1,0);
        queue<pair<int, int>> q; //node, parent

        for(int i=1; i<=V; i++){
            if(seen[i]==1)  continue;
            q.push({i,0});
            seen[i] = 1;

            while(!q.empty()){
                int node = q.front().first;
                int par = q.front().second;
                q.pop();
                
                for(auto next : adj[node]){
                    if(seen[next]==1){
                        if(par!=next)  return true;
                    }
                    else{
                        q.push({next, node});
                        seen[next]=1;
                    }
                }
            }
        }

        return false;
    }

    bool helper(int node, int par, vector<int>& seen){
        seen[node]=1;
        for(auto next : adj[node]){
            if(seen[next]==1){
                if(par!=next) return true;
            }else{
                helper(next, node, seen);
            }
        }
        return false;
    }

    bool cycle_dfs(){
        vector<int> seen(V+1,0);

        for(int i=1; i<=V; i++){
            if(seen[i]==1)  continue;
            if(helper(i,0,seen))  return true;
        }
        return false;
    }
};


int main(){
    Graph g(8, 6); //8 nodes, 6 Edges
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(4,6);
    g.addEdge(7,8);

    cout<<"Adjacency list representation is: "<<endl;
    g.adj_list();

    cout<<"Does it contain cycle (bfs)?? "<<endl;
    if(g.cycle_bfs())  cout << "Yes";
    else  cout << "No";

    cout<<endl;

    cout<<"Does it contain cycle (bfs)?? "<<endl;
    if(g.cycle_dfs()) cout << "Yes";
    else  cout << "No";

    return 0;
}