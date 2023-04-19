class Solution {
public:
    bool help(int i,vector<int>& nums,int tar,vector<vector<int>>&dp){
        if(tar<0)return false;
        if(tar==0)return true;
        if(i==nums.size())return false;
        
        if(dp[i][tar]!=-1)return dp[i][tar];
        return dp[i][tar]=help(i+1,nums,tar,dp)||help(i+1,nums,tar-nums[i],dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it:nums){
            sum+=it;
            
        }
        if(sum%2!=0)return false;
        vector<vector<int>>dp(nums.size(),vector<int>((sum/2)+1,-1));
         return help(0,nums,sum/2,dp);
        
    }
};