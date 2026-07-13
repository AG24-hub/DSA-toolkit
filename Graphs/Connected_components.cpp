// It is done using disjoint set

#include<bits/stdc++.h>
using namespace std;

class DSU{
    vector<int> par, rank;

    public: 

    DSU(int n){
        par.resize(n+1);
        rank.resize(n+1, 0);

        for(int i=0; i<=n; i++)  par[i]=i;
    }

    int findPar(int u){
        if(par[u] == u)  return u;
        return par[u] = findPar(par[u]);
    }

    void unionByRank(int u, int v){
        int pu = findPar(u);
        int pv = findPar(v);

        if(pu == pv) return;

        if(rank[pu] < rank[pv]){
            par[pu] = pv; 
        }
        else{
            par[pv] = pu;
            if(rank[pu] == rank[pv])  rank[pu]++;
        }
    }
};

int main(){
    DSU ds(7);
    vector<int> adj(8);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    if (ds.findPar(3) == ds.findPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionByRank(3, 7);

    if (ds.findPar(3) == ds.findPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}