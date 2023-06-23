class Solution {
public:
    int dfs(vector<vector<int>>& adj,vector<bool>& ap,int i,vector<int>&vis){
        
        int res=0;
        for(int j=0;j<adj[i].size();j++){
            if(vis[adj[i][j]]==0){
                vis[adj[i][j]]=1;
                res+=dfs(adj,ap,adj[i][j],vis);
            }
            
        }
        if(res==0&&!ap[i])return 0;
        return res+2;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& ap) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        vis[0]=1;
        int ans=dfs(adj,ap,0,vis);
        if(ans==0)return 0;
        return ans-2;
    }
};