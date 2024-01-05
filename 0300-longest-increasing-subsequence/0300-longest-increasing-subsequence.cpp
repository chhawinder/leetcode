class Solution {
public:
    int help(vector<int>& nums,int prev,int curr,vector<vector<int>>&dp){
        if(curr==nums.size())return 0;
        if(prev!=-1&&dp[prev+1][curr]!=-1)return dp[prev+1][curr];
        // take
        int take=0;
        if(prev==-1||nums[curr]>nums[prev]){
            take=help(nums,curr,curr+1,dp)+1;
        }
        // ntake
        int ntake=help(nums,prev,curr+1,dp);
        return dp[prev+1][curr]=max(take,ntake);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return help(nums,-1,0,dp);
    }
};