class Solution {
public:
    int help(vector<int>& cost,int i,vector<int>&dp){
        if(i>=cost.size())return 0;
        if(dp[i]!=-1)return dp[i];
       return dp[i]=min(help(cost,i+1,dp),help(cost,i+2,dp))+cost[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        for(int i=2;i<n;i++)
        {
            cost[i]+=min(cost[i-1],cost[i-2]);
        }
        return min(cost[n-1],cost[n-2]);
    }
};