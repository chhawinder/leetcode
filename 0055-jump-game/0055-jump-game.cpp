class Solution {
public:
    bool help(int i,vector<int>& nums,vector<int>&dp){
        if(i==nums.size()-1)return true;
        if(i>=nums.size())return false;
        int maxjump=nums[i];
        if(dp[i]!=-1)return dp[i];
        for(int k=1;k<=maxjump;k++){
            if(help(i+k,nums,dp))return dp[i]=true;
        }
        return dp[i]=false;
    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return help(0,nums,dp);
    }
};