class Solution {
public:
   int findCircleNum(vector<vector<int>>& isConnected) {
    vector<vector<int>> adj(isConnected.size());
    for (int i = 0; i < isConnected.size(); i++) {
        for (int j = 0; j < isConnected[i].size(); j++) {
            if (i != j && isConnected[i][j] == 1) {
                adj[i].push_back(j);
            }
        }
    }
    
    vector<int> vis(isConnected.size(), 0);
    int ans = 0;
    
    for (int i = 0; i < isConnected.size(); i++) {
        if (vis[i] == 0) {
            ans++;
            queue<int> q;
            q.push(i);
            vis[i] = 1;

            while (!q.empty()) {
                int t = q.front();
                q.pop();

                for (auto it : adj[t]) {
                    if (vis[it] == 0) {
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
    }
    
    return ans;
}

};