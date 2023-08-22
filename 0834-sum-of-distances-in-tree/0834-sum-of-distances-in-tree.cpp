class Solution {
public:
    
    int dfs_root(vector<vector<int>>&adj, int root, int prev, int curr_dis) {
        int ans = curr_dis;
        for(auto it : adj[root]){
            if(it != prev)
                ans += dfs_root(adj, it, root, curr_dis + 1);
        }
        return ans;
    }
    
    int dfs_child(vector<vector<int>>&adj, int root, int prev, vector<int>&child) {
        int ans = 1;
        for(auto it : adj[root]){
            if(it != prev)
                ans += dfs_child(adj, it, root, child);
        }
        child[root] = ans;
        return ans;
    }
    
    void dfs_res(vector<vector<int>>&adj, int root, int prev, vector<int>&child, vector<int>&res,int n) {
        if(prev != -1){
            
            res[root] = res[prev] + n - 2 * child[root];
            // cout<<prev<<"::"<<res[prev]<<"-"<<root<<":"<<res[root]<<" ";
        }
        for(auto it : adj[root]){
            if(it != prev)
                dfs_res(adj, it, root, child, res,n);
        }
        
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> res(n, 0);
        vector<int> child(n, 0);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int root_result = dfs_root(adj, 0, -1, 0);
        dfs_child(adj, 0, -1, child);
        // for(auto it: child)cout<<it<<" ";
        res[0] = root_result;
        dfs_res(adj, 0, -1, child, res,n);
        return res;
    }
};
