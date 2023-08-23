class Solution {
public:
    int timer=1;
    void dfs(int n,int parent, vector<vector<int>>& edge,vector<vector<int>>&ans,vector<int>&low,vector<int>&time,vector<int>&vis){
        vis[n]=1;
        low[n]=time[n]=timer++;
        for(auto it:edge[n]){
            if(it==parent)continue;
            if(vis[it]==0){
                dfs(it,n,edge,ans,low,time,vis);
                low[n]=min(low[n],low[it]);
                if(low[it]>time[n]){
                    ans.push_back({it,n});
                   
                }
            }else{
                  low[n]=min(low[n],low[it]);      
            }
            
            
        
                
            
        }
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
               adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        vector<int> time(n);
        vector<int> low(n);
        vector<vector<int>>bridges;
        dfs(0,-1,adj,bridges,low,time,vis);
        return bridges;
        
        
    }
};