// use stack

#include<bits/stdc++.h>
using namespace std;

class Solution{
    private: 
    void dfs(vector<int> adj[], stack<int>& st, vector<int>& seen, int node){
        seen[node] = 1;

        for(auto next : adj[node]){
            if(!seen[next])  dfs(adj, st, seen, next);
        }

        st.push(node);
    }

    public:
    vector<int> Toposort(vector<int> adj[], int V){
        vector<int> ans, seen(V, 0);
        stack<int> st;

        for(int i=0; i<V; i++){
            if(!seen[i]){
               dfs(adj, st, seen, i); 
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
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