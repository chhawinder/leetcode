class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>>adj(isConnected.size()+1);
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected.size();j++){
                if(i!=j&&isConnected[i][j]==1){
                    adj[i+1].push_back(j+1);
                }
            }
        }
        int province=1;
        queue<int>q;
        vector<int>vis(isConnected.size()+1,0);
        q.push(1);
        vis[1]=1;
        while(q.size()){
            int temp=q.front();
            q.pop();
            for(auto it:adj[temp]){
                if(vis[it]==0){
                    vis[it]=1;
                    q.push(it);
                }
            }
            if(q.size()==0){
                for(int i=1;i<=isConnected.size();i++){
                    if(vis[i]==0){
                        vis[i]=1;
                        q.push(i);
                        province++;
                        break;
                    }
                }
            }
        }
        return province;
    }
};