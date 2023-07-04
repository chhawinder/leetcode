class Solution {
public:
    int help(vector<vector<int>>&tree,int headID, vector<int>& manager, vector<int>& informTime){
    int res=0;
    for(auto it:tree[headID]){
        res=max(res,help(tree,it,manager,informTime));
    }
    return res+informTime[headID];
}

  int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    vector<vector<int>>tree(n);
    for(int i=0;i<n;i++){
        if(manager[i]!=-1){
            tree[manager[i]].push_back(i);
        }
    }
    int res=help(tree,headID,manager,informTime);
      return res;
  }

};