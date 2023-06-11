class Solution {
public:
    vector<vector<int>>ans;
    void help(vector<int>& c,int target,vector<int>&res,int  i){
        if(i==c.size()&&target==0){
            ans.push_back(res);
            return;}
        if(i==c.size()||target<0)return;
        help(c,target,res,i+1);
        if(target-c[i]>=0){
            res.push_back(c[i]);
            help(c,target-c[i],res,i);
            res.pop_back();
                
        }
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>res;
        help(candidates,target,res,0);
        return ans;
        
    }
};