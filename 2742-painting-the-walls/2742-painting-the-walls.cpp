class Solution {
public:
    int help(vector<int>& cost, vector<int>& time,int i,int walls,vector<vector<int>>&dp){
        if(walls<=0)return 0;
        if(i==cost.size())return 1e9;
        if(dp[i][walls]!=-1)return dp[i][walls];
        int take=cost[i]+help(cost,time,i+1,walls-1-time[i],dp);
        int ntake=help(cost,time,i+1,walls,dp);
        
        return  dp[i][walls]=min(take,ntake);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<vector<int>>dp(cost.size()+1,vector<int>(cost.size()+1,-1));
        return help(cost,time,0,cost.size(),dp);
    }
};