class Solution {
public:
    int help(vector<int>& cost,int i,vector<int>&dp){
        if(i>=cost.size())return 0;
        if(dp[i]!=-1)return dp[i];
       return dp[i]=min(help(cost,i+1,dp),help(cost,i+2,dp))+cost[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size(),-1);
        return min(help(cost,0,dp),help(cost,1,dp));
    }
};