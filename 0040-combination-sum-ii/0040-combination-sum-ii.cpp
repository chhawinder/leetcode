class Solution {
public:
    void help(vector<int>& c, int target,int i,vector<int>&res,vector<vector<int>>&ans){
        
        if(target==0){
            ans.push_back(res);
            return ;
        }
        for(int j=i;j<c.size();j++){
            if(j>i&&c[j]==c[j-1])continue;
            if(c[j]>target)break;
            res.push_back(c[j]);
            help(c,target-c[j],j+1,res,ans);
            res.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(),c.end());
        vector<vector<int>>ans;
        vector<int>res;
        help(c,target,0,res,ans);
        return ans;
        
    }
};