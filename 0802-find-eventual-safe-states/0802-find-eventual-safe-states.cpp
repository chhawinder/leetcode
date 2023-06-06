class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //reverse graph
        vector<vector<int>>ng(graph.size());
        for(int i=0;i<graph.size();i++){
            for(auto it:graph[i]){
                ng[it].push_back(i);
            }
        }
        //indegree
        vector<int>ind(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            for(auto it:ng[i]){
                ind[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<graph.size();i++){
            if(ind[i]==0)q.push(i);
        }
        vector<int>res;
        while(q.size()){
            int temp=q.front();
            q.pop();
            res.push_back(temp);
            for(auto it:ng[temp]){
                ind[it]--;
                if(ind[it]==0)q.push(it);
            }
            
        }
        sort(res.begin(),res.end());
        return res;
        
    }
};