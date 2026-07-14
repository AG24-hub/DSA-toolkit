// use Khan's algorithm

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> Toposort(vector<int> adj[], int V){
        vector<int> ans, indegree(V, 0);
        queue<int> q;

        for(int i=0; i<V; i++){
            for(int j=0; j<adj[i].size(); j++){
                indegree[adj[i][j]]++;
            }
        }

        for(int i=0; i<V; i++){
            if(indegree[i] == 0)  q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto next : adj[node]){
                indegree[next]--;
                if(indegree[next]==0)  q.push(next);
            }
        }

        return ans;
    }
};

int main(){
    int V=6;
    vector<int> adj[6];
    adj[0] = {};
    adj[1] = {};
    adj[2] = {3};
    adj[3] = {1}; 
    adj[4] = {0,1};
    adj[5] = {0,2}; 

    Solution obj;

    vector<int> ans = obj.Toposort(adj, V);

    cout<<"sorted array is"<< endl;
    for(auto i : ans) cout<<i<<" ";
    cout<<endl;

    return 0;
}