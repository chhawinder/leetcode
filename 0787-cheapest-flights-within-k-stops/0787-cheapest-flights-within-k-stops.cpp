class Solution {
public:
    int help(vector<vector<pair<int,int>>>graph,int s,int d,int k){
        if(s==d)return 0;
        if(k==0)return -1;
        int res=INT_MAX;
        for(int i=0;i<graph[s].size();i++){
            int p=graph[s][i].first;
            int l=graph[s][i].second;
    
           if( help(graph,p,d,k-1)!=-1)res=min(res,l+help(graph,p,d,k-1));
        }
        if(res==INT_MAX)return -1;
 
        return res;
        
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         vector<vector<pair<int, int>>> adj(n);
        for(auto flight : flights){
            // flight[0] represent node i, flight[1] represent neighbor node of node i, flight[2] represent cost between node i to neighbor node
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        //it will store [node, cost]
        queue<pair<int, int>> q;
        q.push({src, 0});
        //it will store minimum cost to reach each node
        vector<int> minCost(n, INT_MAX);
        int stops = 0;
        while(!q.empty() && stops <= k){
            int size = q.size();
            while (size--) {
                auto [currNode, cost] = q.front();
                q.pop();
                for (auto& [neighbour, price] : adj[currNode]) {
                    if (price + cost < minCost[neighbour]){
                        minCost[neighbour] = price + cost;
                        q.push({neighbour, minCost[neighbour]});
                    }
                }
            }
            stops++;
        }
        if(minCost[dst] == INT_MAX)
            return -1;
        return minCost[dst];
        
    }
};