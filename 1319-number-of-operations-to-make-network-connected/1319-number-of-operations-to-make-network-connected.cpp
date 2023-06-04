class Solution {
    void dfs(vector<vector<int>>&adj,vector<int>&vis,int i){
        vis[i]=1;
        for(auto it:adj[i]){
            if(vis[it]==0){
                dfs(adj,vis,it);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)return -1;
        vector<vector<int>>adj(n);
        for(auto v:connections){
            adj[v[0]].push_back(v[1]);
             adj[v[1]].push_back(v[0]);
        }
        
        vector<int>vis(n,0);
        int com=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(adj,vis,i);
                com++;
            }
        }
        return com-1;
    }
};