class Solution {
public:
    void help(vector<int>& nums,set<vector<int>>&res,vector<int>&sub,int i){
        if(i==nums.size()){res.insert(sub);return;}
        help(nums,res,sub,i+1);
        sub.push_back(nums[i]);
        help(nums,res,sub,i+1);
        sub.pop_back();
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>res;
        vector<int>sub;
        help(nums,res,sub,0);
        for(auto it:res){
            ans.push_back(it);
        }
        return ans;
    }
};