class Solution {
public:
    int help(vector<vector<int>>&tree,int index,vector<int>& it){
        int res=0;
        for(auto i:tree[index]){
            res=max(res,help(tree,i,it));
        }
        return res+it[index];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>tree(n);
        for(int i=0;i<manager.size();i++){
            if(manager[i]!=-1)
            tree[manager[i]].push_back(i);
        }
        return help(tree,headID,informTime);
        
    }
};