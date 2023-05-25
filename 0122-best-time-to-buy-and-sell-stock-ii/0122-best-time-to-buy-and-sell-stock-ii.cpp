class Solution {
public:
    int help(vector<int>& prices,int buy, int i,vector<vector<int>>&dp){
        if(i==prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1)return dp[i][buy];
        int take;
        if(buy){
            take=-prices[i]+help(prices,0,i+1,dp);
        }else {
            take=+prices[i]+help(prices,1,i+1,dp);
        }
        int ntake=help(prices,buy,i+1,dp);
        return dp[i][buy]=max(ntake,take);
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return help(prices,1,0,dp);
    }
};